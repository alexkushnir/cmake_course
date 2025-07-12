#include "AdvancedMath.h"
#include <print>
#include <source_location>

namespace advancedmath
{
    double Power(double base, int exponent)
    {
        std::println("Entered {}, with args base: {}, exponent {}", std::source_location::current().function_name(), base, exponent);
        double result = base;
        for (auto count = 1; count < exponent; ++count)
        {
            result = basicmath::Multiply(result, base);
        }

        std::println("Leaving {}, with result: {}", std::source_location::current().function_name(), result);
        return result;
    }

    double Average(double value1, double value2)
    {
        std::println("Entered {}, with args value1: {}, value2 {}", std::source_location::current().function_name(), value1, value2);
        auto result = basicmath::Divide(basicmath::Add(value1, value2), 2);
        std::println("Leaving {}, with result: {}", std::source_location::current().function_name(), result);
        return result;
    }

    int Factorial(int n)
    {
        std::println("Entered {}, with arg n: {}", std::source_location::current().function_name(), n);
        int result = 1;
        
        for (auto count = 2; count <= n; ++count)
        {
            result = basicmath::Multiply(result, count); // uses basic multiply
        }
        
        std::println("Leaving {}, with result: {}", std::source_location::current().function_name(), result);
        return result;
    }
}