# Run:
# --output-on-failure
# --stop-on-failure
# --rerun-failed

cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)

project(catch2_example)

include(CTest)

add_executable(catch2_example Main.cpp)

include(FetchContent)

FetchContent_Declare(catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(catch2)
target_link_libraries(catch2_example PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(catch2_example)