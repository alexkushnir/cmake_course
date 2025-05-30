# Pre-requisite step: sudo apt-get install -y libpqxx-dev
cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17) # Because the libpqxx from apt was compiled with C++17 :(

project(find_module)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/module/")
find_package(PQXX REQUIRED)

add_executable(app Main.cpp)
target_link_libraries(app PRIVATE PQXX::PQXX)


