#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "typetraits.h"

bool isStringFormatOk(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    if (str[0] != '"' || str[str.size() - 1] != '"') {
        return false;
    }
    return true;
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

std::string removeEncapsulatedTokens(const std::string& str) {
    return str.substr(1, str.size() - 2);
}

std::string removeBrackets(const std::string& str) {
    return removeEncapsulatedTokens(str);
}

std::string removeQuotes(const std::string& str) {
    return removeEncapsulatedTokens(str);
}

template <typename T>
std::enable_if_t<std::is_same_v<std::string, T>, T> parse(std::string& value) {
    if (!isStringFormatOk(value)) {
        std::stringstream ss;
        ss << "Error: Invalid string format. Must contain \"s. String: "
           << value;
        throw std::runtime_error(ss.str());
    }
    return removeQuotes(value);
}

template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> parse(std::string& value) {
    T ret{};
    std::stringstream ss(value);
    ss >> ret;
    return ret;
}

template <typename T>
std::enable_if_t<is_vector_type<T>::value, T> parse(std::string& value) {
    using element_type = typename T::value_type;
    T vec;
    if (!isArrayFormatOk(value)) {
        std::stringstream ss;
        ss << "Error: Invalid array format. Array: " << value;
        throw std::runtime_error(ss.str());
    }
    std::istringstream ss(removeBrackets(value));
    std::string token;
    while (std::getline(ss, token, ',')) {
        std::stringstream token_ss(token);
        element_type element;
        token_ss >> element;
        vec.push_back(element);
    }
    return vec;
}

#endif // PARSER_H