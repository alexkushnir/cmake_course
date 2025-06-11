#include <print>
#include <source_location>

void Bar() 
{
    std::println("{}", std::source_location::current().function_name());
}

void FooBar() 
{
    std::println("{} 2", std::source_location::current().function_name());
}