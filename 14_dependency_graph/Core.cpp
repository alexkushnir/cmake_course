#include "Core.h"

#include <print>
#include <source_location>

namespace core
{
    void CoreFunctionality::DoSomething()
    {
        std::println("{}: {} - Core", std::source_location::current().file_name(), std::source_location::current().line());
    }
}