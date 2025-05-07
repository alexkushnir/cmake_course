cmake_minimum_required(VERSION 3.28)

project(OSDetection)

message("Running on ${CMAKE_SYSTEM_NAME} OS, version ${CMAKE_SYSTEM_VERSION}")

add_executable(OSDetection Main.cpp)