project(advancedmath)

add_library(advancedmath SHARED AdvancedMath.cpp)

target_include_directories(advancedmath PUBLIC ${CMAKE_SOURCE_DIR}/basicmath)
target_link_directories(advancedmath PRIVATE ${CMAKE_BINARY_DIR}/basicmath)
target_link_libraries(advancedmath PRIVATE basicmath)