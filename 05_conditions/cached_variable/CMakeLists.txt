cmake_minimum_required(VERSION 3.28)
project(cached)

if (DEFINED VAR1)
    message("VAR1 is defined")
endif()

if (DEFINED CACHE{VAR1})
    message("VAR1 is defined in cache")
endif()

if (DEFINED ENV{VAR1})
    message("VAR1 is defined in cache")
endif()

set(VAR1 TRUE CACHE BOOL VAR1)
message("VAR1 is ${VAR1}")