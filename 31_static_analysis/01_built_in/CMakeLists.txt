cmake_minimum_required(VERSION 3.10)

project(CppCheckTest)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if(CMAKE_CXX_CPPCHECK)
    list(APPEND CMAKE_CXX_CPPCHECK "--enable=warning" "--error-exitcode=1")
endif()

add_executable(CppCheckTest Main.cpp)
