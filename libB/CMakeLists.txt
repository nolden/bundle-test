	add_library(libB SHARED libA.cpp)
message("lib dir: ${ITK_LIBRARY_DIRS}")
message("${ITK_USE_FILE}")
target_link_libraries(libB ITKIO)
install(TARGETS libB DESTINATION plugins)

