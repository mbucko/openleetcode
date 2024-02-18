cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

project(openleetcode
    DESCRIPTION "Open Source version of LeetCode"
    LANGUAGES CXX
)

set(minQt6Version 6.5.0)
   
add_subdirectory(src)

if (TESTING)
    add_subdirectory(test)
endif()