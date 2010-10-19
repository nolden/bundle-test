add_library(libA SHARED libA.cpp)
target_link_libraries(libA libB)

install(TARGETS libA DESTINATION lib)
