foreach (COUNT RANGE 10 24 3)
    message("Foreach loop - count: ${COUNT}")
endforeach()

set(LIST_OF_WORDS1 A list of words)
set(LIST_OF_WORDS2 Another list with another words)

foreach (ENTRY IN LISTS LIST_OF_WORDS1 LIST_OF_WORDS2)
    message("Foreach loop - entry ${ENTRY}")
endforeach()

foreach (ENTRY IN LISTS LIST_OF_WORDS1 LIST_OF_WORDS2)
    message("Foreach loop - entry ${ENTRY}")
    if (ENTRY STREQUAL "with")
        break()
    endif()
endforeach()