cmake_minimum_required(VERSION 3.28)
project(version_file VERSION 7.8.9)
set(CMAKE_CXX_STANDARD 23)

add_library(static STATIC static_library.cpp)
target_sources(static PUBLIC FILE_SET HEADERS
                           BASE_DIRS include
                           FILES include/staticlib/static_library.h
)

include(GNUInstallDirs)
install(TARGETS static EXPORT StaticLibTarget ARCHIVE FILE_SET HEADERS)
install(EXPORT StaticLibTarget
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/static/cmake
  NAMESPACE Library::
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/StaticLibConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion
)

install(FILES "StaticLibConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/StaticLibConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/static/cmake
)