# testrunner.py

import os
import subprocess
import re

from datetime import datetime

import logger
import resultsdiffer

def sort_key(file):
    # Extract the number from the filename
    match = re.search(r'\d+', file)
    if match:
        return int(match.group())
    return file

def printSuccess(testcase_name):
    print(logger.green(testcase_name + ": SUCCESS"))
    print(f"\033[92m{testcase_name}: SUCCESS\033[0m")

def printFailure(testcase_name, message):
    print(logger.red(f"{testcase_name}: FAILURE - {message}"))

def getTestcaseName(file):
    return file[:-5]

def runTests(exec_filename, testcase_dir, output_file_dir, problem_name):
    dated_output_dir = datetime.now().strftime("%Y-%m-%d-%H-%M-%S")
    cur_test_output_dir = os.path.join(output_file_dir, dated_output_dir)
    
    if not os.path.isdir(cur_test_output_dir):
        os.mkdir(cur_test_output_dir)

    for file in sorted(os.listdir(testcase_dir), key=sort_key):
        if not file.endswith(".test"):
            continue

        test_case_name = getTestcaseName(file)
        output_filename = os.path.join(cur_test_output_dir,
                                    f"{test_case_name}.results")
    
        input_filename = os.path.abspath(os.path.join(testcase_dir, file))
        ret, message = runTest(exec_filename, input_filename, output_filename)
        if ret != 0:
            printFailure(test_case_name, message)
            return
        
        ret, message = resultsdiffer.compare(input_filename, output_filename)
        if ret != 0:
            printFailure(test_case_name, message)
            return

        printSuccess(test_case_name)

def runTest(exec_filename, testcase_filename, output_filename):
    if not os.path.isfile(exec_filename):
        return 1, f"The file {exec_filename} does not exist."
    if not os.path.isfile(testcase_filename):
        return 1, f"The file {testcase_filename} does not exist."
    
    try:
        result = subprocess.run([os.path.basename(exec_filename),
                                 os.path.abspath(testcase_filename),
                                 os.path.abspath(output_filename)],
                                shell=True,
                                cwd=os.path.dirname(exec_filename),
                                stderr=subprocess.PIPE)
    except Exception as e:
        return 1, f"Error running the test {e}"
    
    return result.returncode, result.stderr.decode()