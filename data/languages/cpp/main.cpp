#include "problemtest.h"

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

bool openFileForWriting(const std::string &filename, std::ofstream &out) {
    const auto parent_path =
        std::filesystem::path(filename).parent_path();

    if (!std::filesystem::exists(parent_path) ||
        !std::filesystem::is_directory(parent_path)) {
        std::cerr << "Directory " << parent_path << " does not exist"
                  << std::endl;
    }

    std::ofstream outfile(filename);

    if (!outfile.is_open()) {
        std::cerr << "Unable to open file for writing";
        return false;
    }

    out = std::move(outfile);
    return true;
}

std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file> "
                  << "<testcase name>" << std::endl;
        return 1;
    }

    const std::string test_dir_name = argv[1];
    const std::string results_file_name = argv[2];
    const std::string testcase_name = argv[3];

    if (!std::filesystem::is_directory(test_dir_name)) {
        std::cerr << "Error, test directory " << test_dir_name
                  << " does not exist."
                  << std::endl;
        return 1;
    }

    if (std::filesystem::exists(results_file_name)) {
        std::cerr << "Error, results file " << results_file_name
                  << " already exists."
                  << std::endl;
        return 1;
    }

    std::string testcase_file_name;
    if (to_lower(testcase_name) != "all") {
        testcase_file_name = test_dir_name + "/" +
            testcase_name + ".test";
        if (!std::filesystem::exists(testcase_file_name)) {
            std::cerr << "Error, testcase file " << testcase_file_name
                    << " does not exist."
                    << std::endl;
            return 1;
        }
    }

    ProblemTest problemTest(test_dir_name,
                            results_file_name,
                            testcase_file_name);

    const bool success = problemTest.run();

    return success ? 0 : 1;
}
