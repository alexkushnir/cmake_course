project(calctester)

include(CTest)

add_executable(calctester Tester.cpp)
target_link_libraries(calctester calculator)
target_include_directories(calctester PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME "AddTest" COMMAND calctester a)
