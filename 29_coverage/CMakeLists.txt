# cmake --build build -t coverage
cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test_frameworks)

# add_subdirectory(test bin)  
add_subdirectory(test)  