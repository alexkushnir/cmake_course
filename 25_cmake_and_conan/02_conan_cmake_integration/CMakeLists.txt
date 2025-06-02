cmake_minimum_required(VERSION 3.28)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_SOURCE_DIR}/conan_provider.cmake)
project(json_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_SOURCE_DIR}/02_conan_cmake_integration/conan_provider.cmake)

find_package(nlohmann_json REQUIRED)
add_executable(json_parser Main.cpp)
target_link_libraries(json_parser PRIVATE nlohmann_json::nlohmann_json)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/example.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)