cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(pch)

add_executable(pch Main.cpp)
target_precompile_headers(pch PRIVATE <print>)