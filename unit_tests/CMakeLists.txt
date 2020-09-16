#project(unit_test)

include_directories(${rudra_SOURCE_DIR}/include)

link_directories(${rudra_SOURCE_DIR}/src)
add_executable(unit_tests normalize.c)
#target_link_libraries(unit_tests src)
