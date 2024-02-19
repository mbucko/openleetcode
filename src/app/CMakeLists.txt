set(PYTHON_SCRIPTS
    main.py
    resultsdiffer.py
    testrunner.py
)

foreach(PYTHON_SCRIPT IN LISTS PYTHON_SCRIPTS)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PYTHON_SCRIPT} ${PROJECT_BUILDS_DIR}/${PYTHON_SCRIPT} COPYONLY)
endforeach()