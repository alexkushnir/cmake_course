cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(library_user)

add_executable(main_static MainStatic.cpp)
target_link_libraries(main_static PRIVATE static)
