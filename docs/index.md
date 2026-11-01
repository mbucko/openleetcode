# Getting Started

Welcome to the OpenLeetCode Project! This guide describes how a problem is built and tested, and how to add support for a new language.

## Table of Contents

- [Getting Started](#getting-started)
	- [Table of Contents](#table-of-contents)
	- [Directory Layout](#directory-layout)
	- [Building and Running the Testcases](#building-and-running-the-testcases)
			- [Setup](#setup)
			- [Build and Run](#build-and-run)
			- [The Results](#the-results)
	- [Schema Validation](#schema-validation)
	- [Adding support for a new language](#adding-support-for-a-new-language)

## Directory Layout

After installing, the install directory (for example ``install/OpenLeetCode``) contains:

- languages
  - cpp
  - python
- problems
  - TwoSum
    - cpp
    - python
    - testcases
    - description.md
    - metadata.json
- results_validation_schema.json

Each language's test harness lives in its own folder under ``languages``. Each problem has a folder per language with the user's solution file (``solution.cpp``, ``solution.py``), the reference solution (``solution_expected.*``) and its write-up (``solution.md``), plus the shared testcases, description and metadata (LeetCode number and difficulty).

Reinstalling refreshes everything except the users' solution files, which are never overwritten.

## Building and Running the Testcases

#### Setup
When ``openleetcode`` is executed, two of the specified parameters are ``problem`` and ``language``. Let's assume the problem is ``TwoSum`` and the language is ``cpp``.

``openleetcode`` copies the harness files from ``languages/cpp`` into ``problems/TwoSum/cpp``. Missing files are copied, and harness files that differ from the template are refreshed, so harness fixes reach problems that were built before. Solution files are never overwritten.

#### Build and Run
The selected language's harness is then run against the testcases in ``problems/TwoSum/testcases``.

- **C++** is configured and built with CMake. Only the executable being tested is built: ``solution_cpp`` for the user's solution, or ``solution_expected_cpp`` with ``--run-expected-tests``, so a compile error in the user's solution doesn't break runs of the reference solution. Where the compiler supports them, the user's solution is built with AddressSanitizer and UndefinedBehaviorSanitizer, so out-of-bounds access, null dereferences and overflows stop the run and report the line in ``solution.cpp``.
- **Python** runs ``languages/python/problemtest.py``, which loads ``solution.py``, or ``solution_expected.py`` with ``--run-expected-tests``. An error raised by the solution fails that testcase as a runtime error, with the error and the line in ``solution.py``, and stops the run.

``--testcase All`` runs every ``.test`` file except those whose name starts with ``_``. Those only run when requested by name; the UI uses ``_custom_testcase`` for its custom testcase.

#### The Results
The results of a run are stored in ``testcase_output/TwoSum-<datetime>.results``, relative to the directory ``openleetcode`` is run from. The timestamp includes microseconds, so back-to-back runs never share a file.

## Schema Validation
Once ``openleetcode`` has run the harness, it reads the results file, adds the run's ``stderr`` (and ``stdout`` for single-testcase runs), and writes it back. If the harness exited without writing a results file, for example because the solution crashed, ``openleetcode`` writes one with the ``errorcode``, ``stdout`` and ``stderr`` instead.

The ``.results`` file is JSON in the format defined by ``results_validation_schema.json`` in the install directory, and is validated against it. Schema validation keeps the results consistent across languages, which the UI relies on to display them the same way regardless of the language.

## Adding support for a new language

To add a language:

1. Add its harness in ``data/languages/<language>``. It is run with three arguments: the testcases directory, the results file to write, and the testcase name (``All`` or a single testcase). It must:
   - read each ``.test`` file: one line per argument, then the expected output (``*`` means any output is accepted, which the custom testcase uses);
   - skip testcases whose name starts with ``_`` when running ``All``;
   - write a results file that passes ``results_validation_schema.json``, with a complete result for every testcase it ran, including when the solution fails or raises an error.
2. Add a ``<language>`` folder with ``solution.*``, ``solution_expected.*`` and ``solution.md`` to every problem in ``data/problems``.
3. Register the language in ``src/app/openleetcode.py`` (``SUPPORTED_LANGUAGES`` and how to build or run it), in ``src/ui/directory-manager.js`` (``SOLUTION_FILENAMES``) and in ``src/ui/index.js`` (``LANGUAGE_LABELS``).
4. Run every problem's reference solution with ``--run-expected-tests`` in the new language and check that all of them pass.
