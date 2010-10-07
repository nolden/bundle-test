SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/bin")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_subdirectory(libA)
add_subdirectory(main)
