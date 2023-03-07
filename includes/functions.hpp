#pragma once

#include <string>
#include <vector>

// checks if given vector represents a graphic sequence using Havel-Hakimi algorithm
bool isGraphicHavel(std::vector<int> d);
// returns a Prufer code for a given adjacency list
std::string AdjToPrufer(std::vector<std::vector<int>> adj);
// returns an adjacency list for a given Prufer code
std::vector<std::vector<int>> PruferToAdj(std::string);

