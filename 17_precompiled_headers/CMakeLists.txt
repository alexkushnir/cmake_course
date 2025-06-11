cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(pch)

add_executable(pch_external Print.cpp)
target_precompile_headers(pch_external PRIVATE <print>)
