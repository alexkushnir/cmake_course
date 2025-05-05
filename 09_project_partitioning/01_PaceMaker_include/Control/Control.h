#pragma once 

class Control
{
public: 
    Control() = default;
    ~Control() = default;

    void SetControlParameters(const int control1, const int control2);

private:
    int m_control1;
    int m_control2;    
};