cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(configure)

add_executable(configure Main.cpp)

set(ENABLER_FLAG ON)
set(STRING_VARIABLE1 "STRING_VARIABLE1")
set(STRING_VARIABLE2 "STRING_VARIABLE2")

configure_file(Definitions.h.in Defs/Definitions.h)

target_include_directories(configure PRIVATE ${CMAKE_BINARY_DIR})

