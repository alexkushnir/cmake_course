#include <iostream>

void ExampleFunction() 
{
    int x;
    std::cout << x; // Warning: Value stored to 'x' is never read

    int arr[5];
    arr[10] = 0; // Warning: Array index out of bounds
}

int main() 
{
    ExampleFunction();
    return 0;
}