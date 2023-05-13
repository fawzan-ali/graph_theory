#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../includes/functions.hpp"

TEST_CASE("Havel-Hakimi: Empty sequence") {
	std::vector<int> test;
	REQUIRE(isGraphicHavel(test) == false);
}

TEST_CASE("Havel-Hakimi: {0}") {
	std::vector<int> test = { 0 };
	REQUIRE(isGraphicHavel(test) == true);
}

TEST_CASE("Havel-Hakimi: {x}") {
	std::vector<int> test = { 1 };
	std::vector<int> test1 = { 5 };
	std::vector<int> test2 = { -1 };	
	std::vector<int> test3 = { -5 };
	REQUIRE(isGraphicHavel(test) == false);
	REQUIRE(isGraphicHavel(test1) == false);
	REQUIRE(isGraphicHavel(test2) == false);
	REQUIRE(isGraphicHavel(test3) == false);
}

TEST_CASE("Havel-Hakimi: Random") {
	std::vector<int> test = { 5, 1, 1, 1, 1, 1 };
	std::vector<int> test1 = { 6, 6, 5, 4, 3, 3, 3, 3, 2, 1, 0, 0, 0 };
	REQUIRE(isGraphicHavel(test) == true);
	REQUIRE(isGraphicHavel(test1) == true);

}
