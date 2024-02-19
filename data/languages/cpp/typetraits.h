#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <vector>

template <typename T>
struct is_vector_type : std::false_type { };

template <typename T>
struct is_vector_type<std::vector<T>>
    : std::bool_constant<std::is_integral_v<T>> {
    using type = T;
};

#endif // TYPETRAITS_H