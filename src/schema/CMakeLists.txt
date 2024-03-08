set (DATA
    results_validation_schema.json
)

foreach(FILE IN LISTS DATA)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${FILE} ${PROJECT_BUILDS_DIR}/${FILE} COPYONLY)
endforeach()