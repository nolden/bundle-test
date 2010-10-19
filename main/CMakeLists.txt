include_directories(../libA ../libB)
add_executable(Main main.cpp)
# target_link_libraries(Main libA )

install(TARGETS Main RUNTIME DESTINATION bin )
SET(DIRS  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
INSTALL(CODE "
    # use custom version of BundleUtilities
    SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_MODULE_PATH} )
    include(BundleUtilities)
    fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/bin/Main\" \"${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_SHARED_LIBRARY_PREFIX}libA${CMAKE_SHARED_LIBRARY_SUFFIX}\" \"${DIRS}\")
    " COMPONENT Runtime)

