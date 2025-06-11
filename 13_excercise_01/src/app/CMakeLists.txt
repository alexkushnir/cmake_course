project(app)

add_executable(app App.cpp)

target_link_directories(app PRIVATE ${CMAKE_BINARY_DIR}/engine)
target_link_libraries(app PRIVATE engine)
