# Run with --log-context command line switch

function(inner_function)
    list(APPEND CMAKE_MESSAGE_CONTEXT ${CMAKE_CURRENT_FUNCTION})
    message("inner_function message")
endfunction()

function(outer_function)
    list(APPEND CMAKE_MESSAGE_CONTEXT ${CMAKE_CURRENT_FUNCTION})
    message("outer_function message")
    inner_function()
endfunction()

list(APPEND CMAKE_MESSAGE_CONTEXT "top")

message("Before `outer_function`")
outer_function()
message("After `outer_function`")