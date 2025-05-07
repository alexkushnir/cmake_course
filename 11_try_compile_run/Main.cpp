#include <map>
#include <iostream>
#include <format>

int main()
{
    std::map<int, int> m { {1, 2}, {3, 4}, {5, 6} };

    for (const auto& [k, v] : m)
    {
        std::cout << std::format("Key {}, Value {}", k, v) << "\n";
    }

    return 0;
}