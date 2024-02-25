set(PYTHON_SCRIPTS
    functionextractor.py
    logger.py
    openleetcode.py
    testrunner.py
)

set(WINDOWS_SCRIPTS
    openleetcode.bat
)

if (WIN32)
    foreach(WINDOWS_SCRIPT IN LISTS WINDOWS_SCRIPTS)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${WINDOWS_SCRIPT} ${PROJECT_BUILDS_DIR}/${WINDOWS_SCRIPT} COPYONLY)
    endforeach()
endif()

foreach(PYTHON_SCRIPT IN LISTS PYTHON_SCRIPTS)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PYTHON_SCRIPT} ${PROJECT_BUILDS_DIR}/${PYTHON_SCRIPT} COPYONLY)
endforeach()