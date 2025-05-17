#include "Decorator.h"

#include <print>
#include <source_location>

namespace decorators
{
    void Decorator::Decorate()
    {
        std::println("{}: {} - Decorator", std::source_location::current().file_name(), std::source_location::current().line());
    }
}