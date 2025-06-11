cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
project(relocatable_target)

add_library(static STATIC static_library.cpp)
target_sources(static
  PUBLIC FILE_SET HEADERS BASE_DIRS include
  FILES include/staticlib/static_library.h
)

set_target_properties(static PROPERTIES PUBLIC_HEADER include/staticlib/static_library.h)

include(GNUInstallDirs)
install(TARGETS static EXPORT StaticLibTarget ARCHIVE FILE_SET HEADERS)

install(EXPORT StaticLibTarget
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/static/cmake
  NAMESPACE Library::
)

install(FILES StaticLibConfig.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/static/cmake
)