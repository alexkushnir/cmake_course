cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(library_user)

include(${CMAKE_BINARY_DIR}/../library_build/cmake/LibraryTargets.cmake)

include(CMakePrintHelpers)
cmake_print_properties(TARGETS "library::static" PROPERTIES
  IMPORTED_CONFIGURATIONS
  INTERFACE_INCLUDE_DIRECTORIES
)

cmake_print_properties(TARGETS "library::shared" PROPERTIES
  IMPORTED_CONFIGURATIONS
  INTERFACE_INCLUDE_DIRECTORIES
)

add_executable(main_static MainStatic.cpp)
target_link_libraries(main_static PRIVATE library::static)

add_executable(main_shared MainShared.cpp)
target_link_libraries(main_shared PRIVATE library::shared)
