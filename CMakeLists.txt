cmake_minimum_required(VERSION 3.25)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wno-narrowing)

include_directories(include)

add_executable(cpp_stl main.cpp)
