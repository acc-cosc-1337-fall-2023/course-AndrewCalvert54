#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file 
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_gc_content function with AGCTATAG") {
    double result = get_gc_content("AGCTATAG");
    REQUIRE(result == Approx(0.375));
}

TEST_CASE("Test get_gc_content function with CGCTATAG") {
    double result = get_gc_content("CGCTATAG");
    REQUIRE(result == Approx(0.50));
}

TEST_CASE("Test get_reverse_string function with AGCTATAG", "[get_reverse_string]") {
    string result = get_reverse_string("AGCTATAG");
    REQUIRE(result == "GATATCGA");
}

TEST_CASE("Test get_reverse_string function with CGCTATAG", "[get_reverse_string]") {
    string result = get_reverse_string("CGCTATAG");
    REQUIRE(result == "GATATCGC");
}

TEST_CASE("Test get_dna_complement function with AAAACCCGGT", "[get_dna_complement]") {
    string result = get_dna_complement("AAAACCCGGT");
    REQUIRE(result == "ACCGGGTTTT");
}

TEST_CASE("Test get_dna_complement function with CCCGGAAAAT", "[get_dna_complement]") {
    string result = get_dna_complement("CCCGGAAAAT");
    REQUIRE(result == "ATTTTCCGGG");
}