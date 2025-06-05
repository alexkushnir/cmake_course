# Run:
# --output-on-failure
# --stop-on-failure
# --rerun-failed

cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)

project(basic_unit_test)

include(CTest)
include(FetchContent)
 
# For command line parsing
FetchContent_Declare(cxxopts 
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git 
    GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

add_executable(basic_unit_test Tests.cpp)
target_include_directories(basic_unit_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(basic_unit_test PRIVATE ${cxxopts_SOURCE_DIR}/include)

add_test(NAME "RemoteMessageTest_NoArguments" COMMAND basic_unit_test n)
add_test(NAME "RemoteMessageTest_EmptyMessage" COMMAND basic_unit_test e)
add_test(NAME "RemoteMessageTest_NoKeyForArgs" COMMAND basic_unit_test k)
add_test(NAME "RemoteMessageTest_IncompatibleKeys" COMMAND basic_unit_test i)
