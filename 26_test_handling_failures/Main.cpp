#include "catch2/catch_test_macros.hpp"

#include <print>

TEST_CASE("Passed1", "[TestCase1]")
{
    REQUIRE(2 + 2 == 4);
}

TEST_CASE("Passed2", "[TestCase1]")
{
    REQUIRE(2 + 2 == 4);
}

TEST_CASE("Passed3", "[TestCase1]")
{
    REQUIRE(2 + 2 == 4);
}

TEST_CASE("Failed1", "[TestCase1]")
{
    REQUIRE(2 + 2 == 5);
}

TEST_CASE("Failed2", "[TestCase1]")
{
    REQUIRE(2 + 2 == 5);
}