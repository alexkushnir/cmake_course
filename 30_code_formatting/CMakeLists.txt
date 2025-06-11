cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(Formatter)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

add_executable(main Main.cpp)

include(Format)

Format(main .)