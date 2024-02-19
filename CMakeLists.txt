cmake_minimum_required(VERSION 3.12)

set(PROJECT_BUILDS_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR}/problem_builds)

if(NOT CMAKE_INSTALL_PREFIX)
    set(PROJECT_BUILDS_DIR "${PROJECT_BUILDS_DIR_NAME}")
else()
    set(PROJECT_BUILDS_DIR "${CMAKE_INSTALL_PREFIX}")
endif()
message (STATUS "Setting PROJECT_BUILDS_DIR to ${PROJECT_BUILDS_DIR}")

set(CMAKE_FILE_DESTINATION_SUFIX "_destination")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

project(openleetcode
    DESCRIPTION "Open Source version of LeetCode"
)

add_subdirectory(src)
add_subdirectory(data)

if (TESTING)
    add_subdirectory(test)
endif()