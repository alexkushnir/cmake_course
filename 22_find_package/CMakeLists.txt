# Pre-example step: sudo apt-get install -y libboost-all-dev
cmake_minimum_required(VERSION 3.28)
project(find_package_example)
set(CMAKE_CXX_STANDARD 23)
# set(Boost_VERBOSE)

find_package(Boost REQUIRED ALL) 
if (Boost_FOUND)
    message("Boost_FOUND: ${Boost_FOUND}")
    message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
    add_executable(app Main.cpp)
    target_include_directories(app PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(app Boost::timer)
endif()

