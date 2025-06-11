cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)

project(unresolved_symbols)

add_library(A A.cpp)
add_library(B B.cpp)

add_executable(main Main.cpp)
target_link_libraries(main B A)