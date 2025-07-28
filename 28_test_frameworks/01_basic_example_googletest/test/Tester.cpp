#include "Calculator.h"
#include "gtest/gtest.h"

TEST(AdditionTest, HappyPath)
{
    int a = 6;
    int b = 2;
    ASSERT_EQ(a + b, calculator::Add(a, b));
}

TEST(AdditionTest, FloatNumbers)
{
    float a = 6.3;
    float b = 2.4;
    ASSERT_EQ(a + b, calculator::Add(a, b));
}