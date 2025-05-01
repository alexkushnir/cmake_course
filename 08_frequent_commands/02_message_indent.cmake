function(foo)
    list(APPEND CMAKE_MESSAGE_INDENT "    ")
    message("foo message")
endfunction()

message("Before `foo`")
foo()
message("After `foo`")