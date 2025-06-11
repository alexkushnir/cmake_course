#pragma once 

#include <vector>

class Data
{
public:
    Data() = default;
    ~Data() = default;

    std::vector<int> GetData() const;

private:
    std::vector<int> m_data;
};