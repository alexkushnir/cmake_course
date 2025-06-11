cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(target_sources)

add_executable(print_file Main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Build system is Windows, adding ReadFile_Windows.cpp")
    target_sources(print_file PRIVATE ReadFile_Windows.cpp)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Build system is Linux, adding ReadFile_Linux.cpp")
    target_sources(print_file PRIVATE ReadFile_Linux.cpp)
endif()