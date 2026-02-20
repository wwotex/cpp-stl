cmake_minimum_required(VERSION 4.1)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wno-narrowing)

add_executable(cpp_stl main.cpp array.hpp)
