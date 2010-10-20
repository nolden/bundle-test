SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/plugins)
add_library(libC SHARED libA.cpp)
target_link_libraries(libC libB)
install(TARGETS libC DESTINATION plugins)
