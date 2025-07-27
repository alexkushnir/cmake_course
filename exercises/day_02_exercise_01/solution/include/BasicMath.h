#pragma once
#include <type_traits>

// template<typename T>
// concept Arithmetic = std::is_arithmetic_v<T>;

namespace basicmath
{
    void PrintVersion();
      
    template<typename... Args>
    constexpr auto Add(Args... args) // requires (Arithmetic<Args>&& ...)
    {
        return (args + ...);
    }

    template<typename... Args>
    constexpr auto Subtract(Args... args) // requires (Arithmetic<Args>&& ...)
    {
        return (args - ...);
    }

    template<typename... Args>
    constexpr auto Multiply(Args... args) // requires (Arithmetic<Args>&& ...)
    {
        return (args * ...);
    }

    template<typename F, typename... Args>
    constexpr auto Divide(F first, Args... args) // requires Arithmetic<F> && (Arithmetic<Args>&& ...)
    {
        return (first / ... / args); 
    }
}