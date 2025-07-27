cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_SOURCE_DIR}/conan_provider.cmake)
set(PROJECT_NAME filewatcher)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(efsw REQUIRED)

add_executable(${PROJECT_NAME} Main.cpp FileListener.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE efsw::efsw)
