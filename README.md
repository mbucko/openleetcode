OpenLeetCode - An open source version of LeetCode
--------------------------------------------------------
Welcome to the OpenLeetCode Project!

The motivation behind this project is to be able to leetcode on the plane without having internet connection. It is by no means meant to replace or copy leetcode.com.


The motivation behind this project is to be able to practice LeetCode problems on a plane without requiring an internet connection (untill Starlink ramps up). It is by no means intended to replace or replicate leetcode.com.

## Table of Contents

1. [Windows Terminal](#windows-terminal)
    1. [Build](#build)
    2. [Run](#run)
        1. [Windows Terminal](#windows-terminal-1)
        2. [Unix](#unix)
2. [How To Use](#how-to-use)
3. [List of LeetCode Problems](#list-of-leetcode-problems)
4. [Usage](#usage)
5. [Note](#note)
6. [Requirements](#requirements)
7. [Contributing](#contributing)

## Windows Terminal

### Build
```cmd
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DPROBLEM_BUILDS_NAME=problem_builds
cmake --build build
cmake --install build --config Debug
```
### Run
#### Windows Terminal
```cmd
./problem_builds/openleetcode --problem_builds_dir ./problem_builds --language cpp --problem TwoSum
```
#### Unix
```bash
./problem_builds/openleetcode.sh --problem_builds_dir ./problem_builds --language cpp --problem TwoSum
```

## How To Use
The above example runs **TwoSum** problem using **C++**.
After the build succeeds the following directory structure will be generated in the folder specified by ``--problem_builds_dir`` flag. In this example it's a folder called ``problem_builds`` as follows:.

- problem_builds
  - problems
    - TwoSum
      - cpp
        - solution.cpp
        - ...
      - testcases
        - TestCase1.test
        - TestCase2.test
        - ...
      - description.md
    - launguage
      - cpp

Just like for LeetCode you have one file where you solve the problem. For example, for the problem called TwoSum there is **problem_builds/problems/TwoSum/cpp/solution.cpp**. To add new test cases you can create a file in **problem_builds/problems/TwoSum/testcases/** directory with the extension **.test** and your solution will be automatically tested against it.

The problem is a LeetCode problem description in the ***description.md*** file location in the directory for each problem. For example ***problem_builds/problems/TwoSum/description.md***.

The format of the .test files are as follows

```text
arg1
arg2
expected results
```

Each line is either an integral type (1, 4.6 etc.), or an array of integral types. For example:

```text
[1, 2, 4]
8.0
[0, 0]
```

For C++ the supported types are: integral types, strings, vector of integral types.

## List of LeetCode Problems
* TwoSum
* LongestSubstringWithoutRepeatingCharacters
* NumberOfIslands

The problem names are automatically extracted from the folder names inside **data/problems/**.

## Usage
```text
$ python openleetcode.py --help
usage: openleetcode.py [-h] [--language {cpp}] [--list-problems] [--problem problem_name]
                       [--problem_builds_dir dir] [--verbose]

OpenLeetCode problem builder. This script builds and tests a leetcode like problems locally. Currently, it only supports C++ language but it can be extended to support other languages.

options:
  -h, --help            show this help message and exit
  --language {cpp}, -l {cpp}
                        The programming language.
  --list-problems       List problems.
  --problem problem_name, -p problem_name
                        Name of the problem to build and test. Default: TwoSum. Use --list-problems to
                        list all problems.
  --problem_builds_dir dir, -d dir
                        Path to a directory with the problems. Usually ./problem_builds/ directory.
                        Default: problem_builds.
  --verbose, -v         Print verbose output
```

## Note
Curently only C++ is supported but the framework is setup such that other languages can be added. Also, the question description and the solution is yet to be worked on.

## Requirements
This project requires the following to run:

- Python
- CMake 3.12
- Git

## Contributing
Feel free to contribute with code, test cases, or even code reviews.

For a more in-depth guide on how to contribute and information about the inner workings of OpenLeetCode, please refer to the [Docs](docs/index.md).