cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(install_library)

add_library(static STATIC static_library.cpp)
target_sources(static 
    PUBLIC FILE_SET HEADERS BASE_DIRS include
    FILES "include/staticlib/static_library.h"
)

include(GNUInstallDirs)
install(TARGETS static ARCHIVE FILE_SET HEADERS) 

