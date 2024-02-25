#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <string>
#include <vector>

struct Comparator {
    // template <typename T>
    // inline static bool compare(const T& lhs, const T& rhs, bool order = false);

    template <typename T,
              typename = std::enable_if_t<std::is_integral_v<T> ||
                                          std::is_same_v<T, std::string>>>
    inline static bool compare(const T& lhs, const T& rhs, bool order) {
        return lhs == rhs;
    }

    template <typename T,
            typename = std::enable_if_t<std::is_integral_v<T> ||
                                        std::is_same_v<T, std::string>>>
    inline static bool compare(std::vector<T>& lhs,
                               std::vector<T>& rhs,
                               bool order) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
            
        if (order) {
            return lhs == rhs;
        } else {
            std::ranges::sort(lhs);
            std::ranges::sort(rhs);
            return compare(lhs, rhs, true);
        }
    }
};

#endif  // COMPARATOR_H