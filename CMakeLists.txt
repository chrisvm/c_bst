cmake_minimum_required(VERSION 3.6)
project(bst)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES
        src/bst.c
        src/bst.h src/main.c)

add_executable(bst ${SOURCE_FILES})
set_property(TARGET bst PROPERTY C_STANDARD 99)