cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(target_sources)

add_executable(print_file Main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_sources(print_file PRIVATE ReadFile_Windows.cpp)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(print_file PRIVATE ReadFile_Linux.cpp)
endif()