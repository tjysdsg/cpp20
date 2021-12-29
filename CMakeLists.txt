cmake_minimum_required(VERSION 3.20)
project(cpp20)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-stdlib=libc++)

add_executable(basic_concept concepts/basic_concept.cpp)
