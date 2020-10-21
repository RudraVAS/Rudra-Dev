cmake_minimum_required(VERSION 3.9)

project(ann VERSION 1.0.0 DESCRIPTION "Only phase I of ANN")

include(GNUInstallDirs)
add_library(ann SHARED
        src/activation.c
        src/layer_manipulation.c
        src/matrix_operations.c
        src/propogation.c
        src/vector.c
        src/xalloc.c
)

set_target_properties(ann PROPERTIES
                VERSION ${PROJECT_VERSION}
                SOVERSION 1
                PUBLIC_HEADER include/rudra/ann.h)
#set_target_properties(ann PROPERTIES PUBLIC_HEADER include/rudra/ann.h)

target_include_directories(ann PRIVATE include)
target_include_directories(ann PRIVATE src)



install(TARGETS ann
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})