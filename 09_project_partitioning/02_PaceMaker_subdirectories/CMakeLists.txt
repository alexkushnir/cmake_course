cmake_minimum_required(VERSION 3.28)

project(PaceMaker)

add_executable(PaceMaker Main.cpp) 

add_subdirectory(Control)
add_subdirectory(Data)

target_link_libraries(PaceMaker PRIVATE Control Data)