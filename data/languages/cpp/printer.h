#ifndef PRINTER_H
#define PRINTER_H

#include <type_traits>
#include <sstream>
#include <string>

struct Printer {
    // print all integral types
    template <typename U,
              typename std::enable_if_t<std::is_integral_v<U>, int> = 0>
    static void toString(const U& value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    // print vector of all integral types
    template <typename U,
              typename std::enable_if_t<std::is_integral_v<typename U::value_type>, int> = 0>
    static std::string toString(const U& value) {
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < value.size(); ++i) {
            if (i  != 0) {
                ss << ", ";
            }
            ss << value[i];
        }
        ss << "]";
        return ss.str();
    }
};

#endif // PRINTER_H