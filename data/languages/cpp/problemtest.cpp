#include "problemtest.h"

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

#include "binder.h"
#include "comparator.h"
#include "parser.h"
#include "printer.h"
#include "solutionwrapper.h"

namespace {

bool openFileForWriting(const std::string &filename, std::ofstream &out) {
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "Unable to open file for writing";
        return false;
    }

    out = std::move(outfile);
    return true;
}

template <typename T>
void print(std::ostream& out, const T& value) {
    out << Printer::toString(value);
}

std::vector<std::string> getTestFiles(const std::string& test_dir_name,
                                      const std::string& testcase_file_name) {
    std::vector<std::string> test_files;

    if (!testcase_file_name.empty()) {
        test_files.emplace_back(testcase_file_name);
        return test_files;
    }

    std::filesystem::directory_iterator dir_iter(test_dir_name);
    for (const auto& entry : dir_iter) {
        if (entry.is_regular_file() && entry.path().extension() == ".test") {
            test_files.emplace_back(entry.path().string());
        }
    }

    // sort such that Test2 comes before Test10
    std::ranges::sort(test_files, [](const std::string& a,
                                     const std::string& b) {
        auto split = [](const std::string& s) {
            std::string before, number, after;
            std::smatch match;
            if (std::regex_search(s, match, std::regex("(\\D*)(\\d*)(\\D*)"))) {
                before = match[1].str();
                number = match[2].str();
                after = match[3].str();
            }
            return std::make_tuple(before, number.empty() ? -1 : std::stoi(number), after);
        };
        const auto split_a = split(a);
        const auto split_b = split(b);

        if (std::get<1>(split_a) != -1 && std::get<1>(split_b) != -1) {
            return split(a) < split(b);
        }
        return a < b;
    });
    
    return test_files;
}

std::vector<std::string> toLines(const std::string& testcase_file) {
    std::vector<std::string> lines;
    std::ifstream in(testcase_file, std::ios::in);
    std::string line;
    while (std::getline(in, line)) {
        lines.emplace_back(std::move(line));
    }
    return lines;
}

}  // annoymous namespace

ProblemTest::ProblemTest(const std::string& test_dir_name,
                         const std::string& results_file_name,
                         const std::string& testcase_file_name)
    : test_dir_name_(test_dir_name),
      results_file_name_(results_file_name),
      testcase_file_name_(testcase_file_name) {
}

auto getDurationSince(const auto& start) {
    const auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        end - start).count();
}

bool ProblemTest::runTest(
    const std::string& testcase_file_name, nlohmann::json& test) const {
    bool success = false;
    bool areEqual = false;
    Solution solution;

    Binder::return_type ret{};
    Binder::return_type expected{};

    test["testcase_name"] = std::filesystem::path(testcase_file_name).stem();

    try {
        auto lines = toLines(testcase_file_name);
        constexpr size_t expected_testcase_size =
            Binder::func_arg_size_v + 1;
        if (expected_testcase_size != lines.size()) {
            std::cerr << "Incorrect number of parameters specified in the"
                    << " testcase file. Must specify one line per "
                    << "parameter + one line for expected output. "
                    << "Found: " << lines.size() << " Expected: "
                    << expected_testcase_size << "." << std::endl;
            success = false;
        } else {
            string expected_str;
            std::swap(expected_str, lines.back());
            expected = std::move(parse<Binder::return_type>(expected_str));
            ret = std::move(Binder::solve(solution, std::move(lines)));
            success = Comparator::compare(ret, expected, true);
            if (!success) {
                test["reason"] =
                    "Mismatch between expected and actual output.";
            }
        }
    } catch (const std::exception& e) {
        std::stringstream ss;
        std::cerr << "Exception occurred while running the test case. "
                  << "Exception: " << std::string(e.what());
        test["reason"] = "Exception occurred.";
        success = false;
    } catch (...) {
        test["reason"] = "Exception occurred.";
        std::cerr << "Unknown exception occurred while running the test case.";
        success = false;
    }

    if (success) {
        test["status"] = "Success";
    } else {
        test["status"] = "Failed";
        test["expected"] = expected;
        test["actual"] = ret;
        test["testcase_file"] = testcase_file_name;
    }

    return success;
}

bool ProblemTest::run() const {
    const auto start = std::chrono::high_resolution_clock::now();
    bool success = false;
    std::vector<nlohmann::json> testsJason;
    
    const vector<std::string> test_files = getTestFiles(test_dir_name_,
                                                        testcase_file_name_);

    for (const auto& testcase_file : test_files) {
        testsJason.emplace_back();
        success = runTest(testcase_file, testsJason.back());
        if (!success) {
            break;
        }
    }

    nlohmann::json jsonObj;
    jsonObj["duration_ms"] = getDurationSince(start);

    if (success) {
        jsonObj["status"] = "Ok";
        jsonObj["tests"] = testsJason;
    } else {
        jsonObj["status"] = "Failed";
        jsonObj["tests"] = testsJason;
    }

    std::ofstream out;
    if (!openFileForWriting(results_file_name_, out)) {
        std::cerr << "Error: Could not open output file: "
                  << results_file_name_
                  << std::endl;
        return 1;
    }
    out << std::setw(4) << jsonObj << std::endl;

    return true;
}