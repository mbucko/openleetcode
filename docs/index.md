# Getting Started

Welcome to the OpenLeetCode Project! This guide will describe how to add support for a new language.

## Table of Contents

1. [Adding support for a new language](#adding-support-for-a-new-language)
2. [Building and Running the Testcases](#building-and-running-the-testcases)
3. [Schema Validation](#schema-validation)

## Adding support for a new language

The support for each language should be self contained within its own folder, located in ``problems_build/problems/language/<language>``. For example, for C++ there is a folder ``cpp`` as shown below:

- problem_builds
  - problems
    - launguage
      - cpp
      - java
      - python

Any newly added language must adhere to the guidelines in the following sections.

## Building and Running the Testcases

#### Setup
When ``openleetcode`` is executed, two of the specified parameters are ``problem`` and ``language``. In this example, let's assume the problem is ``TwoSum`` and the language is ``Cpp``.

``openleetcode`` copies all files from ``problems_build/language/cpp`` into the  ``problems_build/problems/TwoSum/cpp``, including source files and CMake files. The folder already contains ``solution.cpp`` in the case of C++ laguage.

#### Build and Run
Once the copying is complete, CMake is executed to build the binary and subsequently run it against the specified test cases from ``problems_build/problems/TwoSum/testcases.``.

#### The Results
The results of this run will be stored inside ``problems_build/problems/TwoSum/cpp/testcase_output/TwoSum-<datetime>.results``.


## Schema Validation
Once ``openleetcode`` executes the built binary against the testcases, it then picks up the results file and adds two properties: ``stderr`` and ``stdout`` then write it back to its original location. The ``.result`` file is in a json format specified by a validation schema that is used to validate this results file. The validation schema can be found in ``testcase_output/results_validation_schema.json``.

Once ``openleetcode`` executes the built binary against the test cases, it then retrieves the results file and adds two properties: ``stderr`` and ``stdout`` before writing it back to its original location. The ``.result`` file is in JSON format, as specified by a validation schema in ``testcase_output/results_validation_schema.json``. This schema is also used to validating the results file.

Note: Schema validation ensures consistent formatting of the results file for multiple languages. A UI component will rely on the results file being in a consistent format, regardless of the programming language.