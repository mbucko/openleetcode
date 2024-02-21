#ifndef PRINTER_H
#define PRINTER_H

#include <type_traits>
#include <sstream>
#include <string>

#include "typetraits.h"

struct Printer {
    template <typename T,
              typename std::enable_if_t<std::is_integral_v<T>, int> = 0>
    static std::string toString(const T& value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    template <typename T,
              typename std::enable_if_t<std::is_same_v<std::string, T>,
                                        int> = 0>
    static std::string toString(const T& value) {
        return value;
    }

    template <typename T,
              typename std::enable_if_t<is_vector_type<T>::value, int> = 0>
    static std::string toString(const T& value) {
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