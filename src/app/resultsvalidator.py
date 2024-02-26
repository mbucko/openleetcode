# resultsvalidator.py

import json
    
from jsonschema import validate

import logger

def set_schema(schema):
    global _validation_schema
    _validation_schema = schema

def validateResults(results):
    try:
        validate(instance=results, schema=_validation_schema)
        logger.log("Results JSON is valid against the schema.")
    except Exception as e:
        return -1, f"JSON is not valid against the schema. error={e}"
    return 0, ""

def validateResults(results):
    if not _validation_schema:
        raise ValueError("Validation schema is not set. Please call "
                         "set_schema() before calling validateResults().")
    try:
        validate(instance=results, schema=_validation_schema)
        logger.log("Results JSON is valid against the schema.")
    except Exception as e:
        return -1, f"JSON is not valid against the schema. error={e}"
    return 0, ""