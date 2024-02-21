#include "problemtest.h"

#include "binder.h"
#include "printer.h"
#include "solutionwrapper.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <type_traits>

template <typename T>
void print(std::ostream& out, const T& value) {
    out << Printer::toString(value);
}

std::vector<std::string> toLines(std::istream& in) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.emplace_back(std::move(line));
    }
    return lines;
}

ProblemTest::ProblemTest(std::ifstream in, std::ofstream out)
    : in_(std::move(in)), out_(std::move(out)) {
}

bool ProblemTest::run() {
    Solution solution;

    try {
        const auto ret = Binder::solve(solution, toLines(in_));
        print(out_, ret);
     } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
     } catch (...) {
        std::cerr << "Error: Unknown exception" << std::endl;
        return false;
     }

    return true;
}