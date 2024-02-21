# resultsdiffer.py

import ast
import os

def getExpectedResultsString(content):
    return content.split('\n')[-1]
    
def toType(str):
    try:
        return 0, "", ast.literal_eval(str)
    except Exception as e:
        return -1, f"Error parsing the input: '{str}', error: {e.msg}", None

def compare(testcase_filename, file_actual, order = True):
    try:
        with open(testcase_filename, 'r') as file:
            content = file.read()
            ret, message, expected = toType(getExpectedResultsString(content))
            if ret != 0:
                return ret, message

        with open(file_actual, 'r') as file:
            ret, message, actual = toType(file.read())
            if ret != 0:
                return ret, message

        if isinstance(expected, list):
            equal = diffList(expected, actual, order)
        else:
            equal = diffValue(expected, actual)
        
        if equal:
            return 0, "Success!"
        else:
            return -1, f"Expected value is not equal to the actual value. Expected: {expected}, Actual: {actual}"
    except Exception as e:
        return -1, f"Error comparing the results. Expected: {expected}, Actual: {actual}"
    
def diffList(expected, actual, order):
    if len(expected) != len(actual):
        return False
    if order:
        return [i for i in range(len(expected)) if expected[i] == actual[i]]
    else:
        return sorted(expected) == sorted(actual)
    
def diffValue(expected, actual):
    return expected == actual