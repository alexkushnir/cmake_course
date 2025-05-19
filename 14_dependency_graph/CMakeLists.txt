cmake_minimum_required(VERSION 3.28)
project(dependency_graph)
set(CMAKE_CXX_STANDARD 23)

# include(${CMAKE_SOURCE_DIR}/GraphViz.cmake)

add_executable(app App.cpp)

target_link_libraries(app core)
target_link_libraries(app decorators)

add_library(core Core.cpp)
add_library(decorators SHARED Decorator.cpp)

add_custom_target(print_report ALL
                  COMMAND sh -c "echo Custom target example>>report.txt"
                  BYPRODUCTS report.txt
                  COMMENT "Demonstrating add_custom_target usage"
)
message("CUSTOM_TARGET is ${GRAPHVIZ_CUSTOM_TARGET}")
add_dependencies(print_report app)
