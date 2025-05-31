# conan install <conanfile.txt path> --output-folder=build --build=missing
cmake_minimum_required(VERSION 3.15)
project(json_parser)

find_package(nlohmann_json REQUIRED)

add_executable(json_parser Main.cpp)
target_link_libraries(json_parser PRIVATE nlohmann_json::nlohmann_json)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/example.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)