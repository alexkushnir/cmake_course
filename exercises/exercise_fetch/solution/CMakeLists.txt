cmake_minimum_required(VERSION 3.28)  # version can be different
set(PROJECT_NAME fetchcontent)
project(fetchcontent)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        master 
)

FetchContent_MakeAvailable(fmtlib)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} fmt::fmt)