macro(VeryImportantMacro var)
    set(var "new value")
    message("argument: ${var}")
endmacro()

set(var "first value")
message("var is now: ${var}")
VeryImportantMacro("called value")
message("var is now: ${var}")