cmake_minimum_required(VERSION 3.10)

project(CppCheckTest)

set(CMAKE_CXX_CPPCHECK cppcheck)
add_executable(CppCheckTest Main.cpp)

unset(CMAKE_CXX_CPPCHECK)
add_executable(main Main.cpp)