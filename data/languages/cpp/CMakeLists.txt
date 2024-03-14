cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 
set(JSON_BuildTests OFF CACHE INTERNAL "")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10)
        message(FATAL_ERROR "GCC version must be at least 10!")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10)
        message(FATAL_ERROR "Clang version must be at least 10!")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.23)
        message(FATAL_ERROR "Visual Studio version must be at least 2019!")
    endif()
endif()

project(solution
    DESCRIPTION "Open Source version of LeetCode"
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# Set the build type explicitly
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_BUILD_TYPE Release)

add_executable(solution_cpp)
add_executable(solution_expected_cpp)

target_compile_definitions(solution_expected_cpp PRIVATE EXPECTED)

set(HEADER_FILES
    binder.h
    comparator.h
    parser.h
    printer.h
    problemtest.h
    solutionwrapper.h
    stlincludes.h
    treenode.h
    typetraits.h
)

set(SOURCE_FILES
    main.cpp
    problemtest.cpp
    treenode.cpp
)

target_sources(solution_cpp PRIVATE
    # headers
    ${HEADER_FILES}
    # sources
    ${SOURCE_FILES}
)

target_sources(solution_expected_cpp PRIVATE
    # headers
    ${HEADER_FILES}
    # sources
    ${SOURCE_FILES}
)

target_link_libraries(solution_cpp PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(solution_expected_cpp PRIVATE nlohmann_json::nlohmann_json)

set(CMAKE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

install(TARGETS solution_cpp
    CONFIGURATIONS Release
    RUNTIME DESTINATION ${CMAKE_INSTALL_DIR}
)

install(TARGETS solution_expected_cpp
    CONFIGURATIONS Release
    RUNTIME DESTINATION ${CMAKE_INSTALL_DIR}
)
