#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <algorithm>
#include <cmath>
#include <string>
#include <type_traits>
#include <vector>

struct Comparator {
    // Floating point results match when they are within this distance.
    static constexpr double kFloatTolerance = 1e-5;

    template <typename T,
              typename = std::enable_if_t<std::is_integral_v<T> ||
                                          std::is_same_v<T, std::string>>>
    inline static bool compare(const T& lhs, const T& rhs, bool order) {
        return lhs == rhs;
    }

    template <typename T,
              typename = std::enable_if_t<std::is_floating_point_v<T>>,
              typename = void>
    inline static bool compare(const T& lhs, const T& rhs, bool order) {
        return std::fabs(lhs - rhs) <= kFloatTolerance;
    }

    template <typename T>
    inline static bool compare(std::vector<T>& lhs,
                               std::vector<T>& rhs,
                               bool order) {
        if (lhs.size() != rhs.size()) {
            return false;
        }

        if (!order) {
            std::ranges::sort(lhs);
            std::ranges::sort(rhs);
        }

        for (size_t i = 0; i < lhs.size(); ++i) {
            if (!compare(lhs[i], rhs[i], true)) {
                return false;
            }
        }
        return true;
    }
};

#endif  // COMPARATOR_H
