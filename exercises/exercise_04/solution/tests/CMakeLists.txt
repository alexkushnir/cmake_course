set(PROJ_NAME "calc-tests")
project(${PROJ_NAME})

# set_property(DIRECTORY PROPERTY BINARY_DIR ${CMAKE_BINARY_DIR})

include(CTest)
include(FetchContent)

# Fetch googletest
FetchContent_Declare(googletest 
    GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG main)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJ_NAME} Tests.cpp)
target_include_directories(${PROJ_NAME} PRIVATE "${CMAKE_HOME_DIRECTORY}/basicmath")
target_include_directories(${PROJ_NAME} PRIVATE "${googletest_BINARY_DIR}/include")
target_link_libraries(${PROJ_NAME} gtest gtest_main basicmath)

include(GoogleTest)
gtest_discover_tests(${PROJ_NAME})

# Seems like CMake limitation - the test preset can only query the CMAKE_BINARY_DIR and not subdirectories. 
# The workaround is a simple "hack" - I add a post-build step to copy the CTestTestfile.cmake generated file to CMAKE_BINARY_DIR.
# This is the file that the CTest relies on to run the tests
# https://www.perplexity.ai/search/i-have-a-cmake-project-with-4-z2JV4CxwTEWyLyC7EFjqQQ#25
add_custom_command(TARGET ${PROJ_NAME}
                   POST_BUILD
                   COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/CTestTestfile.cmake ${CMAKE_BINARY_DIR})
