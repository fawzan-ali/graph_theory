#include "../includes/functions.hpp"

#include <algorithm>

bool isGraphicHavel(std::vector<int> d) {
	if (d.empty())
		return false;
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

std::vector<std::vector<int>> PruferToAdj(std::vector<int> prufer) {
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
		tree.at(i).at(least_leaf) = 1;
		tree.at(least_leaf).at(i) = 1;
		--degrees.at(i);
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
