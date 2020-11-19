cmake_minimum_required(VERSION 3.9)

project(dp VERSION 1.0.0 DESCRIPTION "Only phase I of DP")

include(GNUInstallDirs)

add_library(dp SHARED
	src/csv_operations.c
	src/normalization.c
	src/vector.c
	src/xalloc.c
)

set_target_properties(dp PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 1
		PUBLIC_HEADER include/rudra/dp.h)

target_include_directories(dp PRIVATE include)
target_include_directories(dp PRIVATE src)



install(TARGETS dp
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/rudra)
