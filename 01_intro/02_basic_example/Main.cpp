#include "Calculator.h"
#include <print>

int main()
{
    Calculator calc;

    std::println("3 + 5 is {}", calc.Add(3, 5));
    std::println("5 - 3 is {}", calc.Subtract(5, 3));

    return 0;
}