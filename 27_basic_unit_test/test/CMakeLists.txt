# Run:
# --output-on-failure
# --stop-on-failure
# --rerun-failed

cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)

project(basic_unit_test)

include(CTest)
include(FetchContent)

FetchContent_Declare(catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(catch2)

add_executable(basic_unit_test Tests.cpp)
target_include_directories(basic_unit_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(basic_unit_test PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(basic_unit_test)
