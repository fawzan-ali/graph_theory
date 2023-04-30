#include "../includes/functions.hpp"

#include <algorithm>

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
	std::vector<int> prufer;
	std::vector<int> degrees;
	for (auto i = unsigned(0); i < n; ++i) {
		int degree = 0;
		for (auto j = unsigned(0); j < adj.at(i).size(); ++j) {
			++degree;	
		}
		degrees.push_back(degree);	
	}
	for (auto i = unsigned(0); i < n - 2; ++i) {
		int least_leaf = 0;
		while (degrees.at(least_leaf) != 1) {
			++least_leaf;
		}
		auto digit = adj.at(least_leaf).front();
		prufer.push_back(digit);
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

bool hasAtMostOneNonTrivialComponent(std::vector<std::list<int>> adj) {
	// todo
	return true;
}

bool isEulerian(const std::vector<std::list<int>> &adj) {
	return (hasEvenDegreeForAllVertices(adj) && hasAtMostOneNonTrivialComponent(adj));
}
