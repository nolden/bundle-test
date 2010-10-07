include_directories(../libA ../libB)
add_executable(Main main.cpp)
target_link_libraries(Main libA )
install(TARGETS Main RUNTIME DESTINATION bin )

INSTALL(CODE "
    # use custom version of BundleUtilities
    #SET(CMAKE_MODULE_PATH ${MITK_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH} )
    include(BundleUtilities)
    fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/bin/Main\" \"\" \"${DIRS}\")
    " COMPONENT Runtime)

