#include "../includes/functions.hpp"

#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

bool isGraphicHavel(std::vector<int> d) {
	if (d.empty())
		return false; // empty seqeunce is not graphic
	std::sort(d.rbegin(), d.rend());
	auto d_1 = d.at(0);
	auto d_n = d.at(d.size() - 1);
	if (d_n < 0)
        	return false;
	if (d_1 == 0)
        	return true;
	d.erase(d.begin());	
	for (auto i = unsigned(0); i < d.size(); ++i) {
		if (i < d_1)
			--d.at(i);
	}
	return isGraphicHavel(d);
}

std::vector<int> AdjacencyListToPrufer(std::vector<std::list<int>> adj) {
	auto n = adj.size();
	if (n < 2)
		return std::vector<int>();
	std::vector<int> prufer(n - 2, 0);
	std::vector<int> degrees(n, 0);
	for (auto i = unsigned(0); i < n; ++i) {
		int degree = 0;
		for (auto j = unsigned(0); j < adj.at(i).size(); ++j) {
			++degree;	
		}
		degrees.at(i) = degree;	
	}
	for (auto i = unsigned(0); i < n - 2; ++i) {
		int least_leaf = 0;
		while (degrees.at(least_leaf) != 1) {
			++least_leaf;
		}
		auto digit = adj.at(least_leaf).front();
		prufer.at(i) = digit;
		--degrees.at(least_leaf);
		--degrees.at(digit);
		std::erase(adj.at(digit), least_leaf);
		std::erase(adj.at(least_leaf), digit);		
	}
	return prufer;
}

std::vector<std::list<int>> PruferToAdjacencyList(const std::vector<int> &prufer) {
	auto n = prufer.size();
	std::vector<std::list<int>> tree(n + 2, std::list<int>());
	std::vector<int> degrees(n + 2, 1);
	for (auto i = unsigned(0); i < n; ++i) {
		++degrees.at(prufer.at(i));
	}	
	for (auto i = unsigned(0); i < n; ++i) {
		int least_leaf = 0;
		while (degrees.at(least_leaf) != 1) {
			++least_leaf;
		}
		tree.at(prufer.at(i)).push_front(least_leaf);
		tree.at(least_leaf).push_front(prufer.at(i));
		--degrees.at(prufer.at(i));
		--degrees.at(least_leaf);	
	}
	int last_leaf = 0;
	while (degrees.at(last_leaf) != 1) {
		++last_leaf;
	}
	tree.at(n + 1).push_front(last_leaf);
	tree.at(last_leaf).push_front(n + 1);
	return tree;
}

std::vector<int> getDegreeSequence(const std::vector<std::list<int>> &adj) {
	std::vector<int> degrees(adj.size(), 0);
	for (unsigned int i = 0; i < adj.size(); ++i) {
		degrees.at(i) = static_cast<int>(adj.at(i).size());
	}
	return degrees;
}

bool hasEvenDegreeForAllVertices(const std::vector<std::list<int>> &adj) {
	auto degrees = getDegreeSequence(adj);
	for (unsigned int i = 0; i < degrees.size(); ++i) {
		if (degrees.at(i) % 2 != 0)
			return false;
	}
	return true;
}

void BFS(const std::vector<std::list<int>>& adj, const int& v, std::vector<bool>& visited) {
	std::queue<int> q;
	q.push(v);
	visited.at(v) = true;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		auto neighbors = adj.at(u);
		for (const auto& w : neighbors) {
			if (!visited.at(w)) {
				q.push(w);
				visited.at(w) = true;
			}
		}
	}
}

void DFS(const std::vector<std::list<int>>& adj, const int& v, std::vector<bool>& visited) {
	std::stack<int> s;
	s.push(v);
	visited.at(v) = true;
	while (!s.empty()) {
		auto u = s.top();
		s.pop();
		auto neighbors = adj.at(u);
		for (const auto& w : neighbors) {
			if (!visited.at(w)) {
				s.push(w);
				visited.at(w) = true;
			}
		}
	}
}

bool isConnected(const std::vector<std::list<int>>& adj) {
	if (!adj.empty()) {
		std::vector<bool> visited(adj.size());
		BFS(adj, 0, visited);
		for (unsigned i = 0; i < visited.size(); ++i) {
			if (visited.at(i) == false)
				return false;
		}
		return true;
	}
	return false;
}


bool hasAtMostOneNonTrivialComponent(std::vector<std::list<int>> adj) {
	for (unsigned i = 0; i < adj.size(); ++i) {
		if (adj.at(i).empty()) 
			adj.erase(adj.begin() + i);
	}
	return isConnected(adj);
}

bool isEulerian(const std::vector<std::list<int>> &adj) {
	return (hasEvenDegreeForAllVertices(adj) && hasAtMostOneNonTrivialComponent(adj));
}

std::vector<int> EulerCircuit(std::vector<std::list<int>> adj) {
	if (isEulerian(adj)) {
		std::unordered_map<int,int> edge_count;
		for (unsigned int i = 0; i < adj.size(); ++i)
			edge_count[i] = adj.at(i).size();
		std::vector<int> circuit;
		std::stack<int> curr_path;
		curr_path.push(0);
		int curr = 0;
		while (!curr_path.empty()) {
			if (edge_count[curr]) {
				curr_path.push(curr);
				int next = adj.at(curr).back();
				edge_count[curr]--;
				adj.at(curr).pop_back();
				curr = next;
			} else {
				circuit.push_back(curr);
				curr = curr_path.top();
				curr_path.pop();
			}
		}
		return circuit;
	}
	return std::vector<int>();
}
