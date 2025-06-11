#include <windows.h>
#include "ReadFile.h"
#include <print>

std::string ReadFileContent(const std::string& fileName)
{
    std::println("Entered Windows implementation");
    HANDLE hFile = CreateFileA(filePath.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) 
    {
        return "";
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    if (fileSize == INVALID_FILE_SIZE) 
    {
        CloseHandle(hFile);
        return "";
    }

    std::string content(fileSize, '\0');
    DWORD bytesRead;

    if (!ReadFile(hFile, &content[0], fileSize, &bytesRead, NULL)) 
    {
        CloseHandle(hFile);
        return "";
    }

    CloseHandle(hFile);
    
    return content;
}