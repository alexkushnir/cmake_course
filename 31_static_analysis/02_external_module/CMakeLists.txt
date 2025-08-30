cmake_minimum_required(VERSION 3.28)

project(CppCheckTest)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(CppcheckTargets)
add_executable(main Main.cpp)

add_cppcheck(main UNUSED_FUNCTIONS STYLE POSSIBLE_ERROR FAIL_ON_WARNINGS)
