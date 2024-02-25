cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(solution
    DESCRIPTION "Open Source version of LeetCode"
    LANGUAGES CXX
)

# Set the build type explicitly
set(CMAKE_BUILD_TYPE Release)

add_executable(solution_cpp)

target_sources(solution_cpp PRIVATE
    # headers
    binder.h
    parser.h
    printer.h
    problemtest.h
    solutionwrapper.h
    stlincludes.h
    typetraits.h

    # sources
    main.cpp
    problemtest.cpp
)

set(CMAKE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS solution_cpp
    CONFIGURATIONS Release
    RUNTIME DESTINATION ${CMAKE_INSTALL_DIR}
)   