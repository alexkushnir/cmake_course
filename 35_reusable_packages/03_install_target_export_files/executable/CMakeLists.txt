# cmake -S <source-dir> -B <build-dir> -DCMAKE_PREFIX_PATH=/usr/local/lib/static
cmake_minimum_required(VERSION 3.28)
project(FindStaticLibPackage)

find_package(StaticLib REQUIRED)

include(CMakePrintHelpers)
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("StaticLib_FOUND: ${StaticLib_FOUND}")

cmake_print_properties(TARGETS "Library::static" PROPERTIES
    IMPORTED_CONFIGURATIONS
    INTERFACE_INCLUDE_DIRECTORIES
)