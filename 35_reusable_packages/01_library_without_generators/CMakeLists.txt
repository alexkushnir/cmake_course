cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(relocatable_target)

add_library(static STATIC static_library.cpp)
target_include_directories(static INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(static PROPERTIES 
  PUBLIC_HEADER include/staticlib/static_library.h)
