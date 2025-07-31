#include "gtest/gtest.h"
#include "BasicMath.h"

TEST(BasicMathTests, AddTwoPositiveNumbers)
{
    ASSERT_EQ(3 + 4, basicmath::Add(3, 4));
}

TEST(BasicMathTests, AddFourPositiveNumbers)
{
    ASSERT_EQ(3 + 4 + 5 + 6, basicmath::Add(3, 4, 5, 6));
}

TEST(BasicMathTests, SubtractTwoPositiveNumbers)
{
    ASSERT_EQ(5 - 2, basicmath::Subtract(5, 2));
}
