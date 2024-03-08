set(PYTHON_SCRIPTS
    functionextractor.py
    logger.py
    openleetcode.py
    resultsvalidator.py
    testrunner.py
)

set(WINDOWS_SCRIPTS
    openleetcode.bat
)

set(UNIX_SCRIPTS
    openleetcode.sh
)

if (WIN32)
    foreach(WINDOWS_SCRIPT IN LISTS WINDOWS_SCRIPTS)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${WINDOWS_SCRIPT} ${PROJECT_BUILDS_DIR}/${WINDOWS_SCRIPT} COPYONLY)
    endforeach()
elseif (UNIX)
    foreach(UNIX_SCRIPT IN LISTS UNIX_SCRIPTS)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${UNIX_SCRIPT} ${PROJECT_BUILDS_DIR}/${UNIX_SCRIPT} COPYONLY)
    endforeach()

    add_custom_target(
        make_openleetcode_executable ALL
        DEPENDS ${PROJECT_BUILDS_DIR}/openleetcode.sh
    )

    add_custom_command(
        TARGET make_openleetcode_executable
        POST_BUILD
        COMMAND chmod +x ${PROJECT_BUILDS_DIR}/openleetcode.sh
    )
endif()

foreach(PYTHON_SCRIPT IN LISTS PYTHON_SCRIPTS)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PYTHON_SCRIPT} ${PROJECT_BUILDS_DIR}/${PYTHON_SCRIPT} COPYONLY)
endforeach()