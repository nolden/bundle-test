SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/plugins/libB)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/plugins/libB)
add_library(libB SHARED libB.cpp libBExport.h)
message("lib dir: ${ITK_LIBRARY_DIRS}")
message("${ITK_USE_FILE}")
target_link_libraries(libB ITKIO)
install(TARGETS libB DESTINATION plugins/libB)

