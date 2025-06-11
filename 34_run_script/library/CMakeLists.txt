# ldconfig -p | grep libshared
cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(export_library)

add_library(shared SHARED shared_library.cpp)
target_sources(shared 
    PUBLIC FILE_SET HEADERS BASE_DIRS . 
    FILES "shared_library.h"
)

include(GNUInstallDirs)
install(TARGETS shared 
       FILE_SET LIBRARIES DESTINATION "lib"
       FILE_SET HEADERS DESTINATION "include"
)

if (UNIX)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()