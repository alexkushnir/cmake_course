#include "Calculator.h"
#include <utility>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv)
{
    if (argc > 1 && std::strcmp(argv[1], "a") == 0)
    {
        float a = 6.3;
        float b = 2.4;
        auto expectedSum = a + b;
        auto sum = calculator::Add(a, b);
        if (expectedSum != sum)
        {
            std::exit(1);
        }
    }
}