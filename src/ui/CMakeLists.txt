
find_program(NPM_EXECUTABLE npm)
find_program(NPX_EXECUTABLE npx)

set(OPENLEETCODEUI_FILES
    # JavaScript files
    directory-manager.js
    index.js
    main.js
    preload.js

    # HTML files
    index.html

    # CSS files
    styles.css

    # Package files
    package.json
    package-lock.json
)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

foreach(FILE ${OPENLEETCODEUI_FILES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${FILE}
                   ${CMAKE_CURRENT_BINARY_DIR}/${FILE}
                   COPYONLY)
endforeach()

add_custom_target(openleetcodeui_npm_install ALL
    COMMAND ${NPM_EXECUTABLE} install
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running npm install for OpenLeetCodeUI"
)

add_custom_target(openleetcodeui_build ALL
    COMMAND ${NPX_EXECUTABLE} electron-packager . --out=${CMAKE_CURRENT_BINARY_DIR}/OpenLeetCodeUI
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Packaging OpenLeetCodeUi"
    DEPENDS openleetcodeui_npm_install
)

install(DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}/OpenLeetCodeUI/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
    USE_SOURCE_PERMISSIONS
)

if (WIN32)
    set(SCRIPT openleetcodeui.bat)
elseif (UNIX)
    set(SCRIPT openleetcodeui.sh)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${SCRIPT}
               ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
               COPYONLY)
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
        DESTINATION ${PROJECT_NAME})

add_custom_target(
    openleetcodeui_script ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${SCRIPT}
)