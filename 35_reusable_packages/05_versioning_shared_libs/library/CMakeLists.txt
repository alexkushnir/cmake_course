cmake_minimum_required(VERSION 3.28)
project(versioning_shared_libs VERSION 9.8.7)
set(CMAKE_CXX_STANDARD 23)

add_library(shared SHARED shared_library.cpp)
target_sources(shared PUBLIC FILE_SET HEADERS
                           BASE_DIRS include
                           FILES include/sharedlib/shared_library.h
)

set_target_properties(shared PROPERTIES SOVERSION 1.2.3)
include(GNUInstallDirs)
install(TARGETS shared EXPORT SharedLibTarget ARCHIVE FILE_SET HEADERS)

install(TARGETS shared LIBRARY COMPONENT cmp NAMELINK_ONLY)
install(EXPORT SharedLibTarget
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/shared/cmake
  NAMESPACE Library::
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SharedLibConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion
)

install(FILES "SharedLibConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/SharedLibConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/shared/cmake
)

