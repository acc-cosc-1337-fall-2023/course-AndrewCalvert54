#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h" // i have access to the echo_variable gunction in my library

TEST_CASE("Test echo variable function", "function should return the same value as the function argument") {
	REQUIRE(5 == echo_variable(5));
	REQUIRE(50 == echo_variable(50));
	REQUIRE(500 == echo_variable(500));
}

/*test case echo_variable */

/*test case add_to_double_1 with 0 as parameter*/

/*test case add_to_double_1 with 1 as parameter*/

/*test case add_to_double_2 with 0 as parameter*/

/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/

