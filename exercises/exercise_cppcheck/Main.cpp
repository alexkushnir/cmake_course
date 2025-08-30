#include <iostream>

void exampleFunction(int* ptr) 
{
    int x;
    std::cout << x; // Warning: Value stored to 'x' is never read
    if (ptr == nullptr) 
    {
        std::cout << *ptr; // Warning: Dereferencing null pointer
    }
   
    int arr[5];
    arr[10] = 0; // Warning: Array index out of bounds
}

int main() 
{
    exampleFunction(nullptr);
    return 0;
}