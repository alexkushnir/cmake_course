# conan install <conanfile.txt path> --output-folder=build --build=missing
# cmake -S <source tree> -B <build tree> -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake_minimum_required(VERSION 3.15)

if (NOT CMAKE_TOOLCHAIN_FILE)
    message("CMAKE_TOOLCHAIN_FILE is not set!")
    set(CMAKE_TOOLCHAIN_FILE conan_toolchain.cmake)
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(json_parser)

find_package(nlohmann_json REQUIRED)

add_executable(json_parser Main.cpp)
target_link_libraries(json_parser PRIVATE nlohmann_json::nlohmann_json)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/example.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)