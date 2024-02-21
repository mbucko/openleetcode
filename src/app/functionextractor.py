# functionextractor.py

import re

OUTPUT_FILE_PREFIX = "#include \"solutionwrapper.h\"\n\nauto fun = &Solution::"
OUTPUT_FILE_SUFFIX = ";"

def _get_function_name(content):
    match = re.search(r'\bpublic:\s+([\w:<>,\s]+)\s+(\w+)\(', content)
    if match:
        return_type, function_name = match.groups()
        return function_name;
    else:
        return None    

def get_function(input_file_name, output_file_name):
    with open(input_file_name, 'r') as file:
        content = file.read()
        if not content:
            print(f"Could not read the content of {input_file_name}")
            return None
        function_name = _get_function_name(content)
        if not function_name:
            print(f"Could not find the function name in {input_file_name}")
            return None
    with open(output_file_name, 'w') as file:
        ret = file.write(f"{OUTPUT_FILE_PREFIX}" +
                         f"{function_name}" +
                         f"{OUTPUT_FILE_SUFFIX}")
        if not ret:
            print(f"Could not write to {output_file_name}")
            return None
    return function_name