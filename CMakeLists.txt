SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/bin")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)


SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

FIND_PACKAGE(ITK)
link_directories(${ITK_LIBRARY_DIRS})

add_subdirectory(libB)
add_subdirectory(libC)
add_subdirectory(libA)
add_subdirectory(main)

include(CPack)

