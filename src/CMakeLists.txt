include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_UI)
    add_subdirectory(ui)
endif()

add_subdirectory(app)
add_subdirectory(schema)
