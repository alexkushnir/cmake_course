# ctest --build-and-test 28_test_frameworks/ build --build-generator Ninja --test-command ctest --test-dir bin
cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test_frameworks)

add_subdirectory(test bin)  