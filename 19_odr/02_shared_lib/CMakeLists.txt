cmake_minimum_required(VERSION 3.28)
project(odr)
set(CMAKE_CXX_STANDARD 23)

add_library(Foo SHARED Foo.cpp)
add_library(Bar SHARED Bar.cpp)
add_executable(odr_shared1 Main.cpp)
target_link_libraries(odr_shared1 Foo Bar)

add_executable(odr_shared2 Main.cpp)
target_link_libraries(odr_shared2 Bar Foo)
