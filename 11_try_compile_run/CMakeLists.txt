cmake_minimum_required(VERSION 3.28)
project(try_compile_run)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

try_run(run_result compile_result
    ${CMAKE_BINARY_DIR}/test_output
    ${CMAKE_SOURCE_DIR}/Main.cpp
    RUN_OUTPUT_VARIABLE output)

message("compile_result: ${compile_result}")
message("run_result: ${run_result}")
message("output:\n" ${output})
