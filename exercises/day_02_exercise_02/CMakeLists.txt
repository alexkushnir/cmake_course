cmake_minimum_required(VERSION 3.12...3.31)

project(
    zlib
    LANGUAGES C
    VERSION 1.4.1.1
    HOMEPAGE_URL "https://zlib.net/"
    DESCRIPTION "a general-purpose lossless data-compression library")

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)
    message(STATUS "No CMAKE_BUILD_TYPE set -- using Release")
    set(CMAKE_BUILD_TYPE Release)
endif(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)

if(MSVC)
    set(CMAKE_REQUIRED_FLAGS "-WX")
else(MSVC)
    set(CMAKE_REQUIRED_FLAGS "-WError")
endif(MSVC)

if(NOT ZLIB_CONF_WRITTEN)
    set(Z_PREFIX ${ZLIB_PREFIX})
    set(CONF_OUT_FILE ${zlib_BINARY_DIR}/zconf.h.cmakein)
    file(READ ${zlib_SOURCE_DIR}/zconf.h ZCONF_CONTENT LIMIT 245)
    file(WRITE ${CONF_OUT_FILE} ${ZCONF_CONTENT})
    file(APPEND ${CONF_OUT_FILE} "#cmakedefine Z_PREFIX 1\n")
    file(APPEND ${CONF_OUT_FILE} "#cmakedefine HAVE_STDARG_H 1\n")
    file(APPEND ${CONF_OUT_FILE} "#cmakedefine HAVE_UNISTD_H 1\n")
    file(READ ${zlib_SOURCE_DIR}/zconf.h ZCONF_CONTENT OFFSET 244)
    set(FIRST_ITEM TRUE)

    foreach(item IN LISTS ZCONF_CONTENT)
        if(FIRST_ITEM)
            string(APPEND OUT_CONTENT ${item})
            set(FIRST_ITEM FALSE)
        else(FIRST_ITEM)
            string(APPEND OUT_CONTENT "\;" ${item})
        endif(FIRST_ITEM)
    endforeach(item IN LISTS ${ZCONF_CONTENT})

    file(APPEND ${CONF_OUT_FILE} ${OUT_CONTENT})
    set(ZLIB_CONF_WRITTEN
        TRUE
        CACHE BOOL "zconf.h.cmakein was created")
endif(NOT ZLIB_CONF_WRITTEN)

configure_file(${zlib_BINARY_DIR}/zconf.h.cmakein ${zlib_BINARY_DIR}/zconf.h)

include(CheckCSourceCompiles)

check_c_source_compiles(
    "
        #include <stdlib.h>
        static void f(void) __attribute__ ((visibility(\"hidden\")));
        int main(void) {return 0;}
    "
    HAVE___ATTR__VIS_HIDDEN)

set(ZLIB_PUBLIC_HDRS ${zlib_BINARY_DIR}/zconf.h zlib.h)

set(ZLIB_PRIVATE_HDRS
    crc32.h
    deflate.h
    gzguts.h
    inffast.h
    inffixed.h
    inflate.h
    inftrees.h
    trees.h
    zutil.h)

set(ZLIB_SRCS
    adler32.c
    compress.c
    crc32.c
    deflate.c
    gzclose.c
    gzlib.c
    gzread.c
    gzwrite.c
    inflate.c
    infback.c
    inftrees.c
    inffast.c
    trees.c
    uncompr.c
    zutil.c)

if(ZLIB_BUILD_SHARED)
    add_library(
        zlib SHARED ${ZLIB_SRCS} ${ZLIB_PUBLIC_HDRS} ${ZLIB_PRIVATE_HDRS})
    target_include_directories(
        zlib
        PUBLIC ${zlib_BINARY_DIR}>
               ${zlib_SOURCE_DIR}>
               ${CMAKE_INSTALL_INCLUDEDIR}>)
    target_compile_definitions(
        zlib
        PRIVATE ZLIB_BUILD
                $<$<BOOL:${HAVE___ATTR__VIS_HIDDEN}>:HAVE_HIDDEN>)
endif(ZLIB_BUILD_SHARED)

# if(ZLIB_BUILD_STATIC)
    # add_library(zlibstatic STATIC ${ZLIB_SRCS} ${ZLIB_PUBLIC_HDRS}
                                  # ${ZLIB_PRIVATE_HDRS})
    # add_library(ZLIB::ZLIBSTATIC ALIAS zlibstatic)
    # target_include_directories(
        # zlibstatic
        # PUBLIC $<BUILD_INTERFACE:${zlib_BINARY_DIR}>
               # $<BUILD_INTERFACE:${zlib_SOURCE_DIR}>
               # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    # target_compile_definitions(
        # zlibstatic
        # PRIVATE ZLIB_BUILD
                # $<$<BOOL:NOT:${HAVE_FSEEKO}>:NO_FSEEKO>
                # $<$<BOOL:${HAVE___ATTR__VIS_HIDDEN}>:HAVE_HIDDEN>
                # $<$<BOOL:${MSVC}>:_CRT_SECURE_NO_DEPRECATE>
                # $<$<BOOL:${MSVC}>:_CRT_NONSTDC_NO_DEPRECATE>
        # PUBLIC $<$<BOOL:${HAVE_OFF64_T}>:_LARGEFILE64_SOURCE=1>)
    # set_target_properties(
        # zlibstatic PROPERTIES EXPORT_NAME ZLIBSTATIC OUTPUT_NAME
                                                     # z${zlib_static_suffix})
# endif(ZLIB_BUILD_STATIC)

# ============================================================================
# Tests
# ============================================================================
# if(ZLIB_BUILD_TESTING)
    # enable_testing()
    # add_subdirectory(test)
# endif(ZLIB_BUILD_TESTING)

if(ZLIB_BUILD_MINIZIP)
    add_subdirectory(contrib/minizip/)
endif(ZLIB_BUILD_MINIZIP)