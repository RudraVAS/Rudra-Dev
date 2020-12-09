cmake_minimum_required(VERSION 3.5)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -march=native")
add_library(ann SHARED
                src/activation.c
                src/layer_manipulation.c
                src/matrix_operations.c
                src/optimizer.c
                src/propogation.c
                src/vector.c
                src/xalloc.c)

set_target_properties(ann PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 1)

target_include_directories(ann PUBLIC include)
target_include_directories(ann PRIVATE src)

install(TARGETS ann
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
        
install(DIRECTORY "${CMAKE_SOURCE_DIR}/modules/ann/include/rudra"
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})