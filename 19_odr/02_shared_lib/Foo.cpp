#include <print>
#include <source_location>

void Foo() 
{
    std::println("{}", std::source_location::current().function_name());
}

void FooBar() 
{
    std::println("{} 1", std::source_location::current().function_name());
}