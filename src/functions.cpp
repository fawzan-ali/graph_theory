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
	std::vector<int> d_prime;
	for (auto i = unsigned(1); i < d.size(); ++i) {
		if (i < d_1 + 1)
			d_prime.push_back(d.at(i) - 1);
		else 
			d_prime.push_back(d.at(i));
	}
	if (isGraphicHavel(d_prime))
		return true;
	return false;
}

std::vector<int> AdjacencyListToPrufer(std::vector<std::vector<int>> adj) {
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
		unsigned int least_leaf = 0;
		while (degrees.at(least_leaf) != 1) {
			++least_leaf;
		}
		prufer.push_back(adj.at(least_leaf).at(0));
		--degrees.at(least_leaf);
		--degrees.at(adj.at(least_leaf).at(0));
		std::erase(adj.at(adj.at(least_leaf).at(0)), least_leaf);
		std::erase(adj.at(least_leaf), adj.at(least_leaf).at(0));		
	}
	return prufer;
}

std::vector<std::vector<int>> PruferToAdjacencyMatrix(std::vector<int> prufer) {
	auto n = prufer.size();
	std::vector<std::vector<int>> tree(n + 2, std::vector<int>(n + 2, 0));
	std::vector<int> degrees(n + 2, 1);
	for (auto i = unsigned(0); i < n; ++i) {
		++degrees.at(prufer.at(i));
	}	
	for (auto i = unsigned(0); i < n; ++i) {
		int least_leaf = 0;
		while (degrees.at(least_leaf) != 1) {
			++least_leaf;
		}
		tree.at(prufer.at(i)).at(least_leaf) = 1;
		tree.at(least_leaf).at(prufer.at(i)) = 1;
		--degrees.at(prufer.at(i));
		--degrees.at(least_leaf);	
	}
	int last_leaf = 0;
	while (degrees.at(last_leaf) != 1) {
		++last_leaf;
	}
	tree.at(n + 1).at(last_leaf) = 1;
	tree.at(last_leaf).at(n + 1) = 1;
	return tree;
}
