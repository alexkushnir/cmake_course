cmake_minimum_required(VERSION 3.28)

project(PaceMaker)

include(Data/data.cmake)
include(Control/control.cmake)

add_executable(PaceMaker Main.cpp ${control_sources} ${data_sources}) 