cmake_minimum_required(VERSION 3.12)

option(BUILD_UI "Build the OpenLeetCode UI" OFF)

set(PROBLEM_BUILDS_NAME "problem_builds")
set(CMAKE_FILE_DESTINATION_SUFIX "_destination")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

project(openleetcode
    DESCRIPTION "Open Source version of LeetCode"
)

add_subdirectory(src)
add_subdirectory(data)