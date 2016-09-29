cmake_minimum_required(VERSION 2.8)
project(bst)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES
        src/bst.c
        src/bst.h
        src/drivers/main.c
        src/stack.cpp
        src/stack.h)

add_executable(bst ${SOURCE_FILES})
set_property(TARGET bst PROPERTY C_STANDARD 11)
