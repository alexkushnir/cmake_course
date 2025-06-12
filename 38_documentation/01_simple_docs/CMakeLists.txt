cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(basicmath)

add_library(basicmath STATIC BasicMath.cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Doxygen)
GenerateDocs(. docs)