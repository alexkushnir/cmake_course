function(VeryImportantFunction arg)
    message("Function: ${CMAKE_CURRENT_FUNCTION}")
    message("File: ${CMAKE_CURRENT_FUNCTION_LIST_FILE}")
    message("arg: ${arg}")
    
    set(arg "new value")
    message("arg again: ${arg}")
    message("ARGV0: ${ARGV0} ARGV1: ${ARGV1} ARGC: ${ARGC}")
endfunction()


set(arg "first value")
VeryImportantFunction("Value1" "Value2")
message("arg in global scope: ${arg}")