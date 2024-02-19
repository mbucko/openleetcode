# main.py

import argparse
import os
import sys
import shutil

import testrunner

TESTCAST_OUTPUT_DIR = "testcase_output"

def main():
    parser = argparse.ArgumentParser(description="OpenLeetCode problem builder")
    parser.add_argument("--problem_builds_dir", 
                        default=".", 
                        metavar='dir', 
                        type=str, 
                        help=("Path to a directory with the problems. "
                            "Usually ./problem_builds/ directory"))
    parser.add_argument("--language",
                        choices=['cpp'],
                        default="cpp",
                        help="The programming language")
    parser.add_argument("--problem",
                        metavar='problem_name',
                        default="TwoSum",
                        type=str,
                        help="name of the problem to build and test. "
                        "Example: TwoSum")
    
    args = parser.parse_args()

    if not os.path.isdir(args.problem_builds_dir):
        print(f"aaThe directory '{args.problem_builds_dir}' does not exist.")
        sys.exit(1)

    problem_dir = os.path.join(args.problem_builds_dir, "problems", args.problem)
    if not os.path.isdir(problem_dir):
        print(f"The directory {problem_dir} does not exist. "
              "Check the problem_builds_dir and problem arguments.")
        sys.exit(1)

    src_template_dir = os.path.join(args.problem_builds_dir, "languages",
                                    args.language)
    if not os.path.isdir(src_template_dir):
        print(f"The directory {src_template_dir} does not exist. "
              "This usually happen when the language is not supported. "
              "Check the language argument.")
        sys.exit(1)

        
    src_dir = os.path.join(problem_dir, args.language)
    if not os.path.isdir(src_dir):
        print(f"The directory {src_dir} does not exist. "
              "This usually happen when the language is not supported. "
              "Check the language argument.")
        sys.exit(1)

    print(f"Building the problem {args.problem} in {args.language} language.")
    print(f"Problem directory: {problem_dir}")
    print(f"Source directory: {src_dir}")
    print(f"Template source directory: {src_template_dir}")

    # Copy the template source files to the problem directory if they don't
    # already exist
    for file in os.listdir(src_template_dir):
        src_file = os.path.join(src_template_dir, file)
        dst_file = os.path.join(src_dir, file)
        if not os.path.isfile(dst_file):
            print(f"Copying {src_file} to {dst_file}")
            shutil.copy(src_file, dst_file)
            
    # Run the cmake in the src_dir
    os.chdir(src_dir)

    #TODO: Hide the output of the system commands unless they error out
    if os.system("cmake -B build") != 0:
        print("CMake failed!")
        sys.exit(1)

    if os.system("cmake --build build --config Release") != 0:
        print("Build failed!")
        sys.exit(1)

    if os.system("cmake --install build") != 0:
        print("Install failed!")
        sys.exit(1)

    bin_dir = os.path.join("bin")
    
    if not os.path.isdir(bin_dir):
        print(f"The directory {bin_dir} does not exist. "
              "Check the problem_builds_dir and problem arguments.")
        sys.exit(1)

    exe_file = os.path.abspath(os.path.join(bin_dir, f"solution_{args.language}.exe"))
    
    if not os.path.isfile(exe_file):
        print(f"The file {exe_file} does not exist. "
              "Check the problem_builds_dir and problem arguments.")
        sys.exit(1)
    
    testcases_dir = os.path.abspath(os.path.join("../testcases"))

    if not os.path.isdir(testcases_dir):
        print(f"The directory {testcases_dir} does not exist. "
              "Check the problem_builds_dir and problem arguments.")
        sys.exit(1)
    
    if not os.path.isdir(TESTCAST_OUTPUT_DIR):
        os.mkdir(TESTCAST_OUTPUT_DIR)

    output_file_dir = os.path.abspath(os.path.join(TESTCAST_OUTPUT_DIR))

    # Run the tests
    testrunner.runTests(exe_file, testcases_dir, output_file_dir, args.problem)

if __name__ == "__main__":
    main()