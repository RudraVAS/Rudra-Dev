cmake_minimum_required(VERSION 3.5)

project(rudra VERSION 1.0.0)

include(GNUInstallDirs)

add_subdirectory(modules/ann)
add_subdirectory(modules/dp)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_library(rudra SHARED
    modules/ann/src/activation.c
    modules/ann/src/layer_manipulation.c
    modules/ann/src/matrix_operations.c
    modules/ann/src/optimizer.c
    modules/ann/src/propogation.c
    modules/ann/src/vector.c
    modules/ann/src/xalloc.c

    modules/dp/src/csv_operations.c
    modules/dp/src/missing_data.c
    modules/dp/src/normalization.c
    modules/dp/src/operations.c
    modules/dp/src/vector.c
    modules/dp/src/xalloc.c
)

set_target_properties(rudra PROPERTIES
                VERSION ${PROJECT_VERSION}
                SOVERSION 1
                PUBLIC_HEADER include/rudra/rudra.h)

install(TARGETS rudra
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/rudra)
