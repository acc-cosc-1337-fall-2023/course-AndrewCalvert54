#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "repetition.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Factorial Function Tests", "[factorial]") {
    // Test factorial for num = 3, 5, 6
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(6) == 720);
}

TEST_CASE("GCD Function Tests", "[gcd]") {
    // Test gcd for (num1, num2) pairs: (5, 15), (21, 28), (25, 100)
    REQUIRE(gcd(5, 15) == 5);   // GCD of 5 and 15 is 5
    REQUIRE(gcd(21, 28) == 7);  // GCD of 21 and 28 is 7
    REQUIRE(gcd(25, 100) == 25); // GCD of 25 and 100 is 25
}