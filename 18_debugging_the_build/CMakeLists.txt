cmake_minimum_required(VERSION 3.28)
project(inclusion)
set(CMAKE_CXX_STANDARD 23)

add_executable(inclusion Main.cpp)
target_compile_options(inclusion PRIVATE -H)

add_executable(save_intermediate Main.cpp)
target_compile_options(save_intermediate PRIVATE -save-temps=obj)