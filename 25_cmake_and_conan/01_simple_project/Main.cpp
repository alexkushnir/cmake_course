#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: json_parser <path_to_json>\n";
        return 1;
    }

    auto json_path = argv[1];

    nlohmann::json data = nlohmann::json::parse(
        std::ifstream{json_path});

    for (const auto& field : data.items())
    {
        std::cout << field.key() << " : " <<  field.value() << "\n";
    }

    return 0;
}