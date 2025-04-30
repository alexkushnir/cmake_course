set(VAR1 5)
set(VAR2 10)

if (VAR1 LESS VAR2)
    message("VAR1 is less than VAR2")
else()
    message("VAR2 is less than VAR1")
endif()

set(VER1 1.2.3)
set(VER2 1.1.4)

if (VER1 GREATER VER2)
    message("VER1 is greater than VER2")
else()
    message("VER2 is greater than VER1")
endif()

set(STR1 "HELLO1")
set(STR2 "HELLO2")

if (STR1 STRGREATER STR2)
message("STR1 is greater than STR2")
else()
    message("STR2 is greater than STR1")
endif()