#ifndef BINDER_H
#define BINDER_H

#include <functional>
#include <sstream>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <vector>

#include "parser.h"
#include "solutionfunction.h"
#include "solutionwrapper.h"

using SolutionFun = decltype(fun);

class Binder {
    using return_type = typename function_traits<SolutionFun>::return_type;
    using arg_tuple_type = typename function_traits<SolutionFun>::arg_tuple_type;

    template <std::size_t... Is>
    static return_type callFunction(Solution& solution,
                                    arg_tuple_type& args,
                                    std::index_sequence<Is...>) {
        return (solution.*fun)(std::get<Is>(args)...);
    }

    template<std::size_t I = 0, typename... Tp>
    inline static typename std::enable_if<I == sizeof...(Tp), void>::type
    parseArgs(std::tuple<Tp...>&, std::vector<std::string>&) { }

    template<std::size_t I = 0, typename... Tp>
    inline static typename std::enable_if<I < sizeof...(Tp), void>::type
    parseArgs(std::tuple<Tp...>& t, std::vector<std::string>& args) {
        using element_type = std::tuple_element_t<I, std::tuple<Tp...>>;
        std::get<I>(t) = parse<element_type>(args[I]);
        parseArgs<I + 1, Tp...>(t, args);
    }

  public:
    static return_type solve(Solution& solution,
                             std::vector<std::string>&& args) {
        // args will be exactly the size of the number of arguments the
        // function takes + expected return value (as per testcases formatting)
        if (std::tuple_size_v<arg_tuple_type> > args.size()) {
            throw std::invalid_argument("Incorrect number of arguments");
        }

        arg_tuple_type argTuple;
        parseArgs(argTuple, args);
        
        return callFunction(
            solution, argTuple,
            std::make_index_sequence<std::tuple_size_v<arg_tuple_type>>{});
    }
};

#endif // BINDER_H