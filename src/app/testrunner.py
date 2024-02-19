# testrunner.py

import os
import subprocess
from datetime import datetime

import resultsdiffer

def getTestcaseName(file):
    return file[:-5]

def runTests(exec_filename, testcase_dir, output_file_dir, problem_name):
    dated_output_dir = datetime.now().strftime("%Y-%m-%d-%H-%M-%S")
    cur_test_output_dir = os.path.join(output_file_dir, dated_output_dir)
    
    if not os.path.isdir(cur_test_output_dir):
        os.mkdir(cur_test_output_dir)

    for file in os.listdir(testcase_dir):
        if not file.endswith(".test"):
            continue

        test_case_name = getTestcaseName(file)
        output_filename = os.path.join(cur_test_output_dir,
                                    f"{test_case_name}.results")
    
        input_filename = os.path.abspath(os.path.join(testcase_dir, file))
        ret, message = runTest(exec_filename, input_filename, output_filename)
        if ret != 0:
            print(f"{test_case_name}: FAILURE - {message}")
            return
        
        ret, message = resultsdiffer.compare(input_filename, output_filename)
        if ret != 0:
            print(f"{test_case_name}: FAILURE - {message}")
            return

        print(f"{test_case_name}: SUCCESS")

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