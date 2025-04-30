set(STRINGS One Two Three Four Five)
set(NUMBERS 1 2 3 4 5)

foreach (ENTRY IN ZIP_LISTS STRINGS NUMBERS)
    message("Literal: ${ENTRY_0}, Number: ${ENTRY_1}")
endforeach()

foreach (WORD NUM IN ZIP_LISTS STRINGS NUMBERS)
    message("Literal: ${WORD}, Number: ${NUM}")
endforeach()