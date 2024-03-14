cmake_minimum_required(VERSION 3.12)

# Can skip compiler checks since we're not building anything.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

option(BUILD_UI "Build the OpenLeetCode UI" OFF)

set(PROBLEM_BUILDS_NAME "problem_builds")
set(CMAKE_FILE_DESTINATION_SUFIX "_destination")

project(openleetcode
    DESCRIPTION "Open Source version of LeetCode"
)

add_subdirectory(src)
add_subdirectory(data)