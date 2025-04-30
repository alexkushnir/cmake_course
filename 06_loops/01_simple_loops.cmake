set(COUNT 0)

while (COUNT LESS 10)
    math(EXPR COUNT "${COUNT} + 1")
    message("While loop - count: ${COUNT}")
endwhile()

set(COUNT 0)

foreach (COUNT RANGE 10)
    message("Foreach loop - count: ${COUNT}")
endforeach()