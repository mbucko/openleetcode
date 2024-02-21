OpenLeetCode - An open source version of LeetCode
--------------------------------------------------------

### Build
```bash 
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cmake --install build --config Debug
```

### Run
```bash
python.exe problem_builds\main.py --problem_builds_dir ./problem_builds --language cpp --problem TwoSum
```

### How To Use
The above example runs **TwoSum** problem using **C++**.
After the build succeeds the following directory structure will be generated

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
    - launguage
      - cpp

Just like for LeetCode you have one file where you solve the problem. For example, for the problem called TwoSum there is **problem_builds/problems/TwoSum/cpp/solution.cpp**. To add new test cases you can create a file in **problem_builds/problems/TwoSum/testcases/** directory with the extension **.test** and your solution will be automatically tested against it.

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

### List of LeetCode Problems
* TwoSum
* LongestSubstringWithoutRepeatingCharacters
The problem names are automatically extracted from the folder names inside **data/problems/**.

### Note
Curently only C++ is supported but the framework is setup such that other languages can be added. Also, the question description and the solution is yet to be worked on.

### Requirements
This project requires the following to run:

- Python
- CMake 3.12

### Contributing
Feel free to contribute with code, test cases, or even code reviews.