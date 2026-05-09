# testrunner.py

import json
import os
import re
import subprocess

from datetime import datetime

import logger
import resultsvalidator

# In the future this might depend on the language (e.g. for pyhon, use 15s)
PROBLEM_LTE_S = 3

def sort_key(file):
    # Extract the number from the filename
    match = re.search(r'\d+', file)
    if match:
        return int(match.group())
    return file

def printSuccess(testcase_name):
    print(logger.green(testcase_name + ": SUCCESS"))

def printFailure(testcase_name, message):
    print(logger.red(f"{testcase_name}: FAILURE - {message}"))

def getTestcaseName(file):
    return file[:-5]

def getFailureMessage(results, fallback_message):
    if fallback_message:
        return fallback_message

    if results.get("status") != "Failed":
        return ""

    tests = results.get("tests", [])
    for test in tests:
        if test.get("status") != "Failed":
            continue

        testcase_name = test.get("testcase_name", "Unknown")
        reason = test.get("reason", "Test failed.")
        expected = test.get("expected")
        actual = test.get("actual")

        if expected is not None and actual is not None:
            return (
                f"{testcase_name}: {reason} "
                f"expected={expected} actual={actual}"
            )
        return f"{testcase_name}: {reason}"

    return ""

def runTests(exec_filename,
             testcase_dir,
             output_dir_name,
             problem_name,
             testcase_name,
             cwd=None,
             env=None):
    date = datetime.now().strftime("%Y-%m-%d-%H-%M-%S")
    test_restults_filename = os.path.join(output_dir_name,
                                          f"{problem_name}-{date}.results")
    
    if not os.path.isdir(output_dir_name):
        os.mkdir(output_dir_name)
    
    if isinstance(exec_filename, str):
        command = [exec_filename]
    else:
        command = list(exec_filename)

    if len(command) == 0:
        return 1, "Executable command is empty."

    executable = command[0]
    if not os.path.isfile(executable):
        return 1, f"The file {executable} does not exist."
    if True and not os.path.isdir(testcase_dir):
        return 1,  f"The testcase directory {testcase_dir} does not exist."
    
    try:
        command.extend([testcase_dir, test_restults_filename, testcase_name])
        logger.log(f"Running command: {' '.join(command)}")
        subprocess_obj = subprocess.run(command,
                                        cwd=(cwd or os.path.dirname(executable)),
                                        timeout=PROBLEM_LTE_S,
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE,
                                        env=env)
    except subprocess.TimeoutExpired:
        return 1, f"Time Limit Exceeded"
    except Exception as e:
        return 1, f"Error running the test, error={e}"
    
    if not os.path.isfile(test_restults_filename):
        jsonResultsObj = {
            "status": "Failed",
            "stderr": subprocess_obj.stderr.decode('utf-8'),
            "stdout": subprocess_obj.stdout.decode('utf-8'),
            "errorcode": hex(subprocess_obj.returncode)
        }
        with open(test_restults_filename, 'w') as f:
            json.dump(jsonResultsObj, f, indent=4)
    
    # read test_restults_filename into a json object
    with open(test_restults_filename, 'r') as f:
        results = json.load(f)
        results["stderr"] = subprocess_obj.stderr.decode('utf-8')
        if testcase_name != "All":
            results["stdout"] = subprocess_obj.stdout.decode('utf-8')
    
    with open(test_restults_filename, 'w') as f:
        json.dump(results, f, indent=4)

    print(f"Results written to {test_restults_filename}")
    
    ret, message = resultsvalidator.validateResults(results)
    if ret != 0:
        return ret, message
    
    logger.logResults(results)
    
    error_message = getFailureMessage(results,
                                      subprocess_obj.stderr.decode('utf-8'))
    return subprocess_obj.returncode, error_message
