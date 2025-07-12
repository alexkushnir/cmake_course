project(app)

add_executable(app App.cpp)
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/advancedmath)
target_link_directories(app PUBLIC ${CMAKE_BINARY_DIR}/advancedmath)
target_link_libraries(app PUBLIC advancedmath)