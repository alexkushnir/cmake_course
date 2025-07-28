project(app)

add_executable(app App.cpp)
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/advancedmath)
target_link_directories(app PUBLIC ${CMAKE_BINARY_DIR}/advancedmath) # -L
target_link_libraries(app PUBLIC advancedmath) # -l

# https://www.rapidtables.com/code/linux/gcc/gcc-l.html
# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html