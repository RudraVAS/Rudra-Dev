cmake_minimum_required(VERSION 3.5)

add_library(dp SHARED
                src/csv_operations.c
                src/missing_data.c
                src/normalization.c
                src/operations.c
                src/vector.c
                src/xalloc.c
)

set_target_properties(dp PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 1)

target_include_directories(dp PUBLIC include)
target_include_directories(dp PRIVATE src)

install(TARGETS dp
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY "${CMAKE_SOURCE_DIR}/modules/dp/include/rudra"
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})