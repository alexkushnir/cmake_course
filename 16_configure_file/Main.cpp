#include "Defs/Definitions.h"
#include <print>

int main()
{
#ifdef ENABLER_FLAG
    std::println("STRING_VARIABLE1 {0}, STRING_VARIABLE2 {1}", STRING_VARIABLE1, STRING_VARIABLE2);
#endif
}