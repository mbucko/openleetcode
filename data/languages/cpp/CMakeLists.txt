cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 
set(JSON_BuildTests OFF CACHE INTERNAL "")

project(solution
    DESCRIPTION "Open Source version of LeetCode"
    LANGUAGES CXX
) 

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# Set the build type explicitly
set(CMAKE_BUILD_TYPE Release)

add_executable(solution_cpp)

target_sources(solution_cpp PRIVATE
    # headers
    binder.h 
    comparator.h
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

target_link_libraries(solution_cpp PRIVATE nlohmann_json::nlohmann_json)

set(CMAKE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS solution_cpp
    CONFIGURATIONS Release
    RUNTIME DESTINATION ${CMAKE_INSTALL_DIR}
)
