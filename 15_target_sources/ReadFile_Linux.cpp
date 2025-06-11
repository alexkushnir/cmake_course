#include "ReadFile.h"
#include <fstream>
#include <sstream>
#include <print>

std::string ReadFileContent(const std::string& fileName)
{
    std::println("Entered Linux implementation");

    std::ifstream f{ fileName };

    if (!f.is_open())
    {
        return "";
    }

    std::stringstream ss;

    ss << f.rdbuf();

    return ss.str();
}