cmake_minimum_required(VERSION 2.5)
set(description "Data preprocessing functionality")

project(rudra)

include_directories(include)
file(GLOB SOURCES "src/*.c")
#file(GLOB SOURCES1 "test/*.c")

add_executable(rudra ${SOURCES})
target_link_libraries(rudra m)
