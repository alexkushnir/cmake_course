#include "Core.h"
#include "Decorator.h"

int main()
{
    core::CoreFunctionality coreObject;
    decorators::Decorator decoratorObject;

    coreObject.DoSomething();
    decoratorObject.Decorate();
    return 0;
}