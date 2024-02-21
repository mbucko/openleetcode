#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <tuple>
#include <type_traits>
#include <vector>

template <typename F>
struct function_traits;

template <typename R, typename C, typename... Args>
struct function_traits<R(C::*)(Args...) const> {
    using return_type = R;
    using arg_tuple_type = std::tuple<std::decay_t<Args>...>;
};

template <typename R, typename C, typename... Args>
struct function_traits<R(C::*)(Args...)> {
    using return_type = R;
    using arg_tuple_type = std::tuple<std::decay_t<Args>...>;
};

template <typename T>
struct is_vector_type : std::false_type {};

template <typename T>
struct is_vector_type<std::vector<T>> : std::true_type {};

#endif // TYPETRAITS_H