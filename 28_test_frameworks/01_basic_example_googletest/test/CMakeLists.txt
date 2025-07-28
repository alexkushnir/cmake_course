set(PROJ_NAME "calctester")
project(${PROJ_NAME})

include(CTest)
include(FetchContent)

# Fetch googletest
FetchContent_Declare(googletest 
    GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG main)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Tests with googletest
add_executable(${PROJ_NAME} Tester.cpp)
target_include_directories(${PROJ_NAME} PRIVATE "${CMAKE_HOME_DIRECTORY}/src")
target_include_directories(${PROJ_NAME} PRIVATE "${googletest_BINARY_DIR}/include")
target_link_directories(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/lib)
target_link_libraries(${PROJ_NAME} gtest gtest_main calculator)

include(GoogleTest)
gtest_discover_tests(${PROJ_NAME})
