SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/plugins)
add_library(libA SHARED libA.cpp libAExport.h)
target_link_libraries(libA libB)
install(TARGETS libA DESTINATION plugins)
