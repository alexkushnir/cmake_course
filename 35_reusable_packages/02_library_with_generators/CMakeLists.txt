cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(relocatable_target)

add_library(static STATIC static_library.cpp)
target_include_directories(static INTERFACE include)
set_target_properties(static PROPERTIES PUBLIC_HEADER include/staticlib/static_library.h)

include(CMakePrintHelpers)
cmake_print_properties(TARGETS "static" PROPERTIES
  IMPORTED_CONFIGURATIONS
  INTERFACE_INCLUDE_DIRECTORIES
)
