#pragma once

#include <string>
#include <vector>

// checks if given vector represents a graphic sequence using Havel-Hakimi algorithm
bool isGraphicHavel(std::vector<int> d);
// returns a Prufer code for a given adjacency list 
std::vector<int> AdjacencyListToPrufer(std::vector<std::vector<int>> adj);
// returns an adjacency matrix for a given Prufer code
std::vector<std::vector<int>> PruferToAdjacencyMatrix(std::vector<int>);
