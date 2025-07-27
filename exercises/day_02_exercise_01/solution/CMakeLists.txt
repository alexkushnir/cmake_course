cmake_minimum_required(VERSION 3.28)
set(PROJECT_NAME basicmath)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} Main.cpp BasicMath.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)