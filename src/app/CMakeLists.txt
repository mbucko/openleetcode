add_executable(openleetcode)

target_sources(openleetcode PRIVATE
    # headers

    # sources
    main.cpp

    # resources
)

install(TARGETS openleetcode
  CONFIGURATIONS Debug
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)