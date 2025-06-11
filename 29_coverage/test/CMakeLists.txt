set(PROJ_NAME "remote-log-test")
project(${PROJ_NAME})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
endif()

include(CTest)
include(FetchContent)

# Fetch Catch2
FetchContent_Declare(Catch2 
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG devel)
FetchContent_MakeAvailable(Catch2)

enable_testing()

# Tests with Catch2
set(CATCH2_TARGET ${PROJ_NAME})
add_executable(${CATCH2_TARGET} catch2test.cpp)
target_include_directories(${CATCH2_TARGET} PUBLIC "${CMAKE_HOME_DIRECTORY}/src")
target_link_libraries(${CATCH2_TARGET} PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(${CATCH2_TARGET})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_options(${CATCH2_TARGET} PRIVATE --coverage)
    target_link_options(${CATCH2_TARGET} PUBLIC --coverage)
    add_custom_command(TARGET ${CATCH2_TARGET} PRE_BUILD COMMAND
    find ${CMAKE_BINARY_DIR} -type f -name '*.gcda' -exec rm {} +)
endif()

include(Coverage)
RunCoverageReport(${CATCH2_TARGET})