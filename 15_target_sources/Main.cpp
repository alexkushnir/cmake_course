#include "ReadFile.h"

#include <filesystem>
#include <print>

int main()
{
    auto testFile = "testFile.txt";
    auto currentPath = std::filesystem::current_path();

    auto fullPath = currentPath / testFile;

    auto str = ReadFileContent(fullPath.string());
    return 0;
}