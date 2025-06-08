cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(export_library)

set(EXPORT_DIR "${CMAKE_BINARY_DIR}/cmake")

add_library(static STATIC static_library.cpp)
target_sources(static 
    PUBLIC FILE_SET HEADERS BASE_DIRS . 
    FILES "static_library.h"
)

add_library(shared SHARED shared_library.cpp)
target_sources(shared 
    PUBLIC FILE_SET HEADERS BASE_DIRS . 
    FILES "shared_library.h"
)

export(TARGETS static shared
       FILE "${CMAKE_BINARY_DIR}/cmake/LibraryTargets.cmake"
       NAMESPACE library::
)
