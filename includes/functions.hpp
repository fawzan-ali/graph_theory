#pragma once

#include <vector>
#include <list>

// checks if a given degree sequence represents a graphic sequence using Havel-Hakimi algorithm
bool isGraphicHavel(std::vector<int>);

// returns a Prufer code for a given tree 
std::vector<int> AdjacencyListToPrufer(std::vector<std::list<int>>);

// returns a tree for a given Prufer code
std::vector<std::list<int>> PruferToAdjacencyList(const std::vector<int>&);

// returns a degree sequence for a given loopless graph
std::vector<int> getDegreeSequence(const std::vector<std::list<int>>&);

// checks if every vertex of a given undirected graph has even degree
bool hasEvenDegreeForAllVertices(const std::vector<std::list<int>>&);

// returns a vector representing a BFS on a graph
void BFS(const std::vector<std::list<int>>&, const int&, std::vector<bool>&);

// returns a vector representing a DFS on a graph
void DFS(const std::vector<std::list<int>>&, const int&, std::vector<bool>&);

// checks if a graph is connected 
bool isConnected(const std::vector<std::list<int>>&);

// checks if a given undirected graph has at most one non-trivial component
bool hasAtMostOneNonTrivialComponent(std::vector<std::list<int>>);

// checks if a given undirected graph has an Euler circuit
bool isEulerian(const std::vector<std::list<int>>&);

// returns an Euler circuit
std::vector<int> EulerCircuit(std::vector<std::list<int>>);

// returns the edges of a graph
std::vector<std::pair<int,int>> getEdges(std::vector<std::list<int>>);

// returns minimum spanning tree using Kruskal's algorithm
std::vector<std::pair<int,int>> Kruskal(const std::vector<std::list<int>>&);

// returns minimum spanning tree using Prim's algorithm
std::vector<std::pair<int,int>> Prim(const std::vector<std::list<int>>&);

// returns a vector of distances from starting node
std::vector<int> Djikstra(const std::vector<std::list<std::pair<int, int>>>&, const int&);
