
set(PYTHON_SCRIPTS
    functionextractor.py
    logger.py
    openleetcode.py
    resultsvalidator.py
    testrunner.py
)

set(WINDOWS_SCRIPT
    openleetcode.bat
)

set(UNIX_SCRIPT
    openleetcode.sh
)

if (WIN32)
    set(SCRIPT ${WINDOWS_SCRIPT})
elseif (UNIX)
    set(SCRIPT ${UNIX_SCRIPT})
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${SCRIPT}
                ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
                COPYONLY)
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
        DESTINATION ${PROJECT_NAME})

add_custom_target(
    openleetcode_script ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
)

foreach(PYTHON_SCRIPT IN LISTS PYTHON_SCRIPTS)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PYTHON_SCRIPT}
                   ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_SCRIPT}
                   COPYONLY)
    install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_SCRIPT}
            DESTINATION ${PROJECT_NAME})
endforeach()
