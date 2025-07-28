########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(efsw_COMPONENT_NAMES "")
if(DEFINED efsw_FIND_DEPENDENCY_NAMES)
  list(APPEND efsw_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES efsw_FIND_DEPENDENCY_NAMES)
else()
  set(efsw_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(efsw_PACKAGE_FOLDER_RELEASE "/home/alex/.conan2/p/efsw81740c0f85eb6/p")
set(efsw_BUILD_MODULES_PATHS_RELEASE )


set(efsw_INCLUDE_DIRS_RELEASE "${efsw_PACKAGE_FOLDER_RELEASE}/include")
set(efsw_RES_DIRS_RELEASE )
set(efsw_DEFINITIONS_RELEASE )
set(efsw_SHARED_LINK_FLAGS_RELEASE )
set(efsw_EXE_LINK_FLAGS_RELEASE )
set(efsw_OBJECTS_RELEASE )
set(efsw_COMPILE_DEFINITIONS_RELEASE )
set(efsw_COMPILE_OPTIONS_C_RELEASE )
set(efsw_COMPILE_OPTIONS_CXX_RELEASE )
set(efsw_LIB_DIRS_RELEASE "${efsw_PACKAGE_FOLDER_RELEASE}/lib")
set(efsw_BIN_DIRS_RELEASE )
set(efsw_LIBRARY_TYPE_RELEASE STATIC)
set(efsw_IS_HOST_WINDOWS_RELEASE 0)
set(efsw_LIBS_RELEASE efsw)
set(efsw_SYSTEM_LIBS_RELEASE m pthread)
set(efsw_FRAMEWORK_DIRS_RELEASE )
set(efsw_FRAMEWORKS_RELEASE )
set(efsw_BUILD_DIRS_RELEASE )
set(efsw_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(efsw_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${efsw_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${efsw_COMPILE_OPTIONS_C_RELEASE}>")
set(efsw_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${efsw_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${efsw_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${efsw_EXE_LINK_FLAGS_RELEASE}>")


set(efsw_COMPONENTS_RELEASE )