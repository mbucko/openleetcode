set (DATA
    results_validation_schema.json
)

foreach(FILE IN LISTS DATA)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${FILE}
                   ${CMAKE_CURRENT_BINARY_DIR}/${FILE}
                   COPYONLY)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${FILE}
    DESTINATION ${PROJECT_NAME})
endforeach()
