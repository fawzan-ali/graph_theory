#pragma once

#include <string>
#include <vector>

// returns a vector of non-negative integers from a given CSV file
std::vector<int> degrees(std::string &filename);
// checks if given vector represents a graphic sequence using Havel-Hakimi algorithm
bool isGraphicHavel(std::vector<int> d);
// checks if given vector represents a graphic sequence using the Erdős–Gallai theorem
bool isGraphicErdos(std::vector<int> const &d);
// returns the minimum of two unsigned ints (if equal, returns first)
unsigned int min(unsigned int const &first, unsigned int const &second);