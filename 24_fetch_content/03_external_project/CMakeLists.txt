cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)

project(catch2_example)
add_executable(catch2_example Main.cpp)

configure_file(ExternalProjectCMakeLists.txt.in catch2-download/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/catch2-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/catch2-download"
)
add_subdirectory("${CMAKE_BINARY_DIR}/catch2-src"
                 "${CMAKE_BINARY_DIR}/catch2-build"
)

target_link_libraries(catch2_example PRIVATE Catch2::Catch2WithMain)

include(CMakePrintHelpers)
cmake_print_properties(TARGETS Catch2::Catch2 PROPERTIES TYPE SOURCE_DIR INTERFACE_INCLUDE_DIRECTORIES)