import importlib.util
import inspect
import json
import os
import re
import sys
import time

from typing import get_args
from typing import get_origin

from treenode import TreeNode

ANY_VALUE = "*"


def split_top_level(value, delimiter):
    tokens = []
    token = []
    depth = 0
    in_string = False
    escape = False

    for char in value:
        if escape:
            token.append(char)
            escape = False
            continue

        if char == "\\" and in_string:
            token.append(char)
            escape = True
            continue

        if char == "\"":
            in_string = not in_string
            token.append(char)
            continue

        if not in_string:
            if char == "[":
                depth += 1
            elif char == "]":
                depth -= 1
            elif char == delimiter and depth == 0:
                tokens.append("".join(token).strip())
                token = []
                continue

        token.append(char)

    if token or value == "":
        tokens.append("".join(token).strip())
    return [token for token in tokens if token != ""]


def parse_bool(value):
    if value == "true":
        return True
    if value == "false":
        return False
    raise ValueError(f"Invalid boolean format: {value}")


def parse_string(value):
    if len(value) < 2 or value[0] != "\"" or value[-1] != "\"":
        raise ValueError(f"Invalid string format: {value}")
    return bytes(value[1:-1], "utf-8").decode("unicode_escape")


def parse_array(value, element_type):
    stripped = value.strip()
    if len(stripped) < 2 or stripped[0] != "[" or stripped[-1] != "]":
        raise ValueError(f"Invalid array format: {value}")
    inner = stripped[1:-1].strip()
    if inner == "":
        return []
    return [parse_typed_value(token, element_type)
            for token in split_top_level(inner, ",")]


def build_tree(values):
    if not values or values[0] is None:
        return None

    root = TreeNode(values[0])
    queue = [root]
    index = 1

    while queue and index < len(values):
        node = queue.pop(0)

        if index < len(values) and values[index] is not None:
            node.left = TreeNode(values[index])
            queue.append(node.left)
        index += 1

        if index < len(values) and values[index] is not None:
            node.right = TreeNode(values[index])
            queue.append(node.right)
        index += 1

    return root


def parse_tree(value):
    stripped = value.strip()
    if stripped == "null":
        return None
    if len(stripped) < 2 or stripped[0] != "[" or stripped[-1] != "]":
        raise ValueError(f"Invalid tree format: {value}")

    inner = stripped[1:-1].strip()
    if inner == "":
        return None

    values = []
    for token in split_top_level(inner, ","):
        token = token.strip()
        if token == "null":
            values.append(None)
        else:
            values.append(int(token))
    return build_tree(values)


def parse_typed_value(value, annotation):
    value = value.strip()

    if annotation is inspect._empty:
        raise ValueError("All Python solution parameters and returns need type hints.")

    if annotation is bool:
        return parse_bool(value)
    if annotation is int:
        return int(value)
    if annotation is str:
        return parse_string(value)
    if annotation is TreeNode:
        return parse_tree(value)

    origin = get_origin(annotation)
    args = get_args(annotation)
    if origin is list:
        if len(args) != 1:
            raise ValueError(f"Unsupported list annotation: {annotation}")
        return parse_array(value, args[0])

    raise ValueError(f"Unsupported annotation: {annotation}")


def serialize_tree(root):
    if root is None:
        return []

    result = []
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node is None:
            result.append(None)
            continue
        result.append(node.val)
        queue.append(node.left)
        queue.append(node.right)

    while result and result[-1] is None:
        result.pop()
    return result


def serialize_value(value):
    if value is None:
        return "None"
    if isinstance(value, TreeNode):
        return serialize_tree(value)
    if isinstance(value, list):
        return [serialize_value(item) for item in value]
    return value


def compare_values(actual, expected):
    return serialize_value(actual) == serialize_value(expected)


def get_testcase_name(filename):
    base = os.path.basename(filename)
    if base.endswith(".test"):
        return base[:-5]
    return base


def read_lines(filename):
    with open(filename, "r", encoding="utf-8") as handle:
        return [line.rstrip("\n") for line in handle]


def get_test_files(test_dir_name, testcase_name):
    if testcase_name.lower() != "all":
        filename = os.path.join(test_dir_name, testcase_name + ".test")
        if not os.path.isfile(filename):
            raise FileNotFoundError(f"Testcase file does not exist: {filename}")
        return [filename]

    test_files = []
    for entry in os.listdir(test_dir_name):
        if entry.endswith(".test"):
            test_files.append(os.path.join(test_dir_name, entry))

    def sort_key(path):
        return [
            int(text) if text.isdigit() else text.lower()
            for text in re.split(r"([0-9]+)", os.path.basename(path))
        ]

    return sorted(test_files, key=sort_key)


def load_solution_class():
    expected = os.environ.get("OPENLEETCODE_EXPECTED") == "1"
    filename = "solution_expected.py" if expected else "solution.py"
    filepath = os.path.join(os.getcwd(), filename)

    spec = importlib.util.spec_from_file_location("openleetcode_solution", filepath)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"Could not load solution module from {filepath}")

    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    solution_class = getattr(module, "Solution", None)
    if solution_class is None:
        raise RuntimeError(f"Solution class not found in {filename}")
    return solution_class


def get_solution_method(solution):
    methods = []
    for name, method in inspect.getmembers(solution, predicate=callable):
        if name.startswith("_"):
            continue
        if getattr(method, "__self__", None) is not solution:
            continue
        methods.append((name, method))

    if len(methods) != 1:
        raise RuntimeError("Solution must define exactly one public method.")
    return methods[0]


def run_test(solution_class, testcase_file_name, test):
    solution = solution_class()
    method_name, method = get_solution_method(solution)
    signature = inspect.signature(method)

    test["testcase_name"] = get_testcase_name(testcase_file_name)

    lines = read_lines(testcase_file_name)
    expected_testcase_size = len(signature.parameters) + 1
    if len(lines) != expected_testcase_size:
        reason = (
            "Incorrect number of parameters specified in the testcase file. "
            "Must specify one line per parameter + one line for expected output. "
            f"Found: {len(lines)} Expected: {expected_testcase_size}."
        )
        test["status"] = "Failed"
        test["reason"] = reason
        test["expected"] = ""
        test["actual"] = ""
        test["testcase_file"] = testcase_file_name
        return False

    expected_str = lines[-1]
    arg_lines = lines[:-1]
    parameters = list(signature.parameters.values())
    parsed_args = [
        parse_typed_value(arg_lines[index], parameter.annotation)
        for index, parameter in enumerate(parameters)
    ]

    actual = method(*parsed_args)
    if expected_str == ANY_VALUE:
        test["status"] = "Skipped"
        test["actual"] = serialize_value(actual)
        return True

    expected = parse_typed_value(expected_str, signature.return_annotation)
    if compare_values(actual, expected):
        test["status"] = "Success"
        return True

    test["status"] = "Failed"
    test["reason"] = "Mismatch between expected and actual output."
    test["expected"] = serialize_value(expected)
    test["actual"] = serialize_value(actual)
    test["testcase_file"] = testcase_file_name
    return False


def main():
    if len(sys.argv) < 4:
        print(
            f"Usage: {sys.argv[0]} <testcase directory> <results output file> "
            "<testcase name>",
            file=sys.stderr,
        )
        return 1

    test_dir_name = sys.argv[1]
    results_file_name = sys.argv[2]
    testcase_name = sys.argv[3]

    start = time.time()
    tests_json = []
    success = True

    try:
        solution_class = load_solution_class()
        test_files = get_test_files(test_dir_name, testcase_name)
        for testcase_file in test_files:
            test_json = {}
            tests_json.append(test_json)
            success = run_test(solution_class, testcase_file, test_json)
            if not success:
                break
    except Exception as error:
        tests_json.append({
            "status": "Failed",
            "testcase_name": testcase_name,
            "reason": "Exception occurred.",
            "expected": "",
            "actual": "",
            "testcase_file": test_dir_name,
        })
        print(str(error), file=sys.stderr)
        success = False

    json_obj = {
        "duration_ms": int((time.time() - start) * 1000),
        "testcase_filter_name": testcase_name,
        "status": "Ok" if success else "Failed",
        "tests": tests_json,
    }

    with open(results_file_name, "w", encoding="utf-8") as handle:
        json.dump(json_obj, handle, indent=4)

    return 0 if success else 1


if __name__ == "__main__":
    raise SystemExit(main())
