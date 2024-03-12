#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "typetraits.h"

void removeOuterSpaces(std::string& value) {
    const auto start = value.find_first_not_of(' ');
    const auto end = value.find_last_not_of(' ');
    value = value.substr(start, end - start + 1);
}

bool hasEncapsulatedTokens(const std::string& str, char start, char end) {
    if (str.empty()) {
        return false;
    }
    if (str[0] != start || str[str.size() - 1] != end) {
        return false;
    }
    return true;
}

bool isCharFormatOk(const std::string& str) {
    return hasEncapsulatedTokens(str, '\"', '\"');
}

bool isStringFormatOk(const std::string& str) {
    return hasEncapsulatedTokens(str, '\"', '\"');
}

bool isArrayFormatOk(const std::string& str) {
    return hasEncapsulatedTokens(str, '[', ']');
}

std::string removeEncapsulatedTokens(const std::string& str) {
    return str.substr(1, str.size() - 2);
}

std::string removeBrackets(const std::string& str) {
    return removeEncapsulatedTokens(str);
}

std::string removeQuotes(const std::string& str) {
    return removeEncapsulatedTokens(str);
}

std::vector<std::string> splitIgnoreBrackets(const std::string& str,
                                             char delimiter) {
    std::vector<std::string> result;
    std::string token;
    int level = 0;
    for (char c : str) {
        if (c == '[') {
            ++level;
        } else if (c == ']') {
            --level;
        }

        if (c == delimiter && level == 0) {
            result.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }

    if (!token.empty()) {
        result.push_back(token);
    }
    return result;
}

template <typename T>
std::enable_if_t<std::is_same_v<char, T>, T> parse(std::string& value) {
    removeOuterSpaces(value);
    if (value.size() != 3 || !isCharFormatOk(value)) {
        std::stringstream ss;
        ss << "Error: Invalid char format. Must be of length 3 and contain "
           << "\"s. String: " << value;
        throw std::runtime_error(ss.str());
    }
    return value[1];
}

template <typename T>
std::enable_if_t<std::is_same_v<std::string, T>, T> parse(std::string& value) {
    removeOuterSpaces(value);
    if (!isStringFormatOk(value)) {
        std::stringstream ss;
        ss << "Error: Invalid string format. The input string must be enclosed" 
              " in quotes. Current value: " << value;
        throw std::runtime_error(ss.str());
    }
    return removeQuotes(value);
}

template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> parse(const std::string& value) {
    std::string valueCopy = value;
    removeOuterSpaces(valueCopy);
    T ret{};
    std::stringstream ss(valueCopy);
    ss >> ret;
    return ret;
}

template <typename T>
std::enable_if_t<is_vector_type<T>::value, T> parse(auto&& value) {
    using element_type = typename T::value_type;
    removeOuterSpaces(value);
    T vec;
    if (!isArrayFormatOk(value)) {
        std::stringstream ss;
        ss << "Error: Invalid array format. Array: " << value;
        throw std::runtime_error(ss.str());
    }

    std::vector<std::string> tokens =
        splitIgnoreBrackets(removeBrackets(value), ',');
    for (std::string& token : tokens) {
        vec.push_back(parse<element_type>(token));
    }
    return vec;
}

#endif // PARSER_H