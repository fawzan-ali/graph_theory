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

TEST_CASE("AdjToPrufer: Two node tree") {
	std::list<int> r0 = { 1 };
	std::list<int> r1 = { 0 };
	std::vector<std::list<int>> test = { r0, r1 };
	auto result = AdjacencyListToPrufer(test);
	std::vector<int> solution;
	REQUIRE(result == solution);
	
}

TEST_CASE("AdjToPrufer: Random") {
	std::list<int> r0 = { 3 };
	std::list<int> r1 = { 3 };
	std::list<int> r2 = { 3 };
	std::list<int> r3 = { 4, 2, 1, 0 };
	std::list<int> r4 = { 5, 3 };
	std::list<int> r5 = { 4 };
	std::vector<std::list<int>> test = { r0, r1, r2, r3, r4, r5 };
	auto result = AdjacencyListToPrufer(test);
	std::vector<int> solution = { 3, 3, 3, 4 };
	REQUIRE(result == solution);
}

TEST_CASE("PruferToAdj: Empty code") {
	std::vector<int> test;
	auto result = PruferToAdjacencyList(test);
	std::list<int> r0 = { 1 };
	std::list<int> r1 = { 0 };
	std::vector<std::list<int>> solution = { r0, r1 };
	REQUIRE(result == solution);
}

TEST_CASE("PruferToAdj: Random") {	
	std::vector<int> test = { 3, 3, 3, 4 };
	auto result = PruferToAdjacencyList(test);
	std::list<int> r0 = { 3 };
	std::list<int> r1 = { 3 };
	std::list<int> r2 = { 3 };
	std::list<int> r3 = { 4, 2, 1, 0 };
	std::list<int> r4 = { 5, 3 };
	std::list<int> r5 = { 4 };
	std::vector<std::list<int>> solution = { r0, r1, r2, r3, r4, r5 };
	REQUIRE(result == solution);
}	
