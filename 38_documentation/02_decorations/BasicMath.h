#pragma once
#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

namespace basicmath
{
    /**
      This class does some simple calculations
    */
    class BasicMath
    {
        public:
        /**
          @brief This function prints the library version
          @details This function prints the library version, it was added to utilize the cpp file also
        */
        void PrintVersion();
        
        
        /**
          @brief This function adds arguments of arithmetic type
          @details this function receives an arguments pack and uses fold expression to add all arguments
         */
        template<typename... Args>
        constexpr auto Add(Args... args) requires (Arithmetic<Args>&& ...)
        {
            return (args + ...);
        }

        /**
          @brief This function substracts arguments of arithmetic type
          @details this function receives an arguments pack and uses fold expression to subtract all arguments
         */
        template<typename... Args>
        constexpr auto Subtract(Args... args) requires (Arithmetic<Args>&& ...)
        {
            return (args - ...);
        }

        /**
          @brief This function multiplies arguments of arithmetic type
          @details this function receives an arguments pack and uses fold expression to multiply all arguments 
         */
        template<typename... Args>
        constexpr auto Multiply(Args... args) requires (Arithmetic<Args>&& ...)
        {
            return (args * ...);
        }

        /**
          @brief This function divides arguments of arithmetic type
          @details this function receives an arguments pack and uses fold expression to divide all arguments
         */
        template<typename F, typename... Args>
        constexpr auto Divide(F first, Args... args) requires Arithmetic<F> && (Arithmetic<Args>&& ...)
        {
            return (first / ... / args); 
        }
    };
}