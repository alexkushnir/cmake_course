cmake_minimum_required(VERSION 3.28)

project(configure_preset)

add_executable(configure_preset Main.cpp)

include(GNUInstallDirs)
install(TARGETS configure_preset
  RUNTIME COMPONENT runtime
)