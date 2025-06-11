cmake_policy(SET CMP0057 NEW)

set(LIST1 A list with a several words)

if ("several" IN_LIST LIST1)
    message("Word several found in list!")
endif()

if (COMMAND set)
    message("Command set exists!")
endif()

if (EXISTS "05_conditions/03_checks.cmake")
    message("03_checks.cmake exists!")
endif()

if (IS_DIRECTORY "05_conditions")
    message("05_conditions is directory!")
endif()

if (IS_SYMLINK "05_conditions/03_checks.cmake")
    message("03_checks.cmake is a symlink!")
endif()

if (IS_ABSOLUTE "05_conditions")
    message("05_conditions is an absolute path!")
endif()
