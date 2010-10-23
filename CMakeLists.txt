cmake_minimum_required(VERSION 2.8)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/bin" "${CMAKE_INSTALL_PREFIX}/plugins" "${CMAKE_INSTALL_PREFIX}/plugins/libB" )
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)


SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

SET (CMAKE_SHARED_LIBRARY_PREFIX "lib")

FIND_PACKAGE(ITK)
link_directories(${ITK_LIBRARY_DIRS})
include_directories(${ITK_INCLUDE_DIRS})

add_subdirectory(libB)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/libB")

add_subdirectory(libC)
add_subdirectory(libA)
add_subdirectory(main)

include(CPack)
include(InstallRequiredSystemLibraries)
