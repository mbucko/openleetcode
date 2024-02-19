#include "problemtest.h"

#include "printer.h"
#include "solutionwrapper.h"
#include "typetraits.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <type_traits>

struct has_twoSum {
    template <typename T, typename = decltype(&T::twoSum)>
    static constexpr bool test(int) { return true; }

    template <typename T>
    static constexpr bool test(...) { return false; }

    static constexpr bool value = test<Solution>(0);
};

constexpr bool has_twoSum_v = has_twoSum::value;

template <typename T>
void print(std::ostream& out, const T& value) {
    out << Printer::toString(value);
}

bool isArrayFormatOk(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    if (str[0] != '[' || str[str.size() - 1] != ']') {
        return false;
    }
    return true;
}

std::string removeBrackets(const std::string& str) {
    return str.substr(1, str.size() - 2);
}

template <typename T>
T parse(std::string& value) {
    constexpr bool is_integral_type_v = std::is_integral_v<T>;
    constexpr bool is_vector_type_v = is_vector_type<T>::value;

    if constexpr (is_integral_type_v) {
        T ret;
        stringstream ss(value);
        ss >> ret;
        return ret;
    } else if constexpr (is_vector_type_v) {
        using element_type = typename is_vector_type<T>::type;
        T vec;
        if (!isArrayFormatOk(value)) {
            stringstream ss;
            ss << "Error: Invalid array format. Array: " << value;
            throw std::runtime_error(ss.str());
        }
        std::istringstream ss(removeBrackets(value));
        std::string token;
        while (std::getline(ss, token, ',')) {
            vec.push_back(parse<element_type>(token));
        }
        return vec;
    } else {
        std::cerr << "Error: Unsupported type" << std::endl;
        return {};
    }
}

auto callSolutionFunction(Solution& solution, std::vector<std::string>& args) {
    if constexpr (has_twoSum_v) {
        auto vec = parse<std::vector<int>>(args[0]);
        return solution.twoSum(vec, parse<int>(args[1]));
    }

    std::cerr << "Error: Unsopported function in Solution" << std::endl;
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
    std::vector<std::string> argsLines = toLines(in_);
    Solution solution;

    try {
        const auto ret = callSolutionFunction(solution, argsLines);
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