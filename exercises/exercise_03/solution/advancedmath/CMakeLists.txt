project(advancedmath)

add_library(advancedmath SHARED AdvancedMath.cpp)

target_include_directories(advancedmath PUBLIC ${CMAKE_SOURCE_DIR}/basicmath)
target_link_directories(advancedmath PRIVATE ${CMAKE_BINARY_DIR}/basicmath) # -L
target_link_libraries(advancedmath PRIVATE basicmath) # -l

# https://www.rapidtables.com/code/linux/gcc/gcc-l.html
# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html