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

def runTests(exec_filename,
             testcase_dir,
             output_dir_name,
             problem_name,
             testcase_name):
    date = datetime.now().strftime("%Y-%m-%d-%H-%M-%S")
    test_restults_filename = os.path.join(output_dir_name,
                                          f"{problem_name}-{date}.results")
    
    if not os.path.isdir(output_dir_name):
        os.mkdir(output_dir_name)
    
    if not os.path.isfile(exec_filename):
        return 1, f"The file {exec_filename} does not exist."
    if True and not os.path.isdir(testcase_dir):
        return 1,  f"The testcase directory {testcase_dir} does not exist."
    
    try:
        command = (
            f"{exec_filename} "
            f"{testcase_dir} "
            f"{test_restults_filename} "
            f"{testcase_name}"
        )
        logger.log(f"Running command: {command}")
        subprocess_obj = subprocess.run(command,
                                        shell=True,
                                        cwd=os.path.dirname(exec_filename),
                                        timeout=PROBLEM_LTE_S,
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)

    except subprocess.TimeoutExpired:
        return 1, f"Time Limit Exceeded"
    except Exception as e:
        return 1, f"Error running the test, error={e}"
    
    if not os.path.isfile(test_restults_filename):
        return 1, f"The file {test_restults_filename} does not exist."
    
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
    
    return subprocess_obj.returncode, subprocess_obj.stderr.decode('utf-8')