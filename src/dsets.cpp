#include "../includes/dsets.hpp"

void DisjointSets::addelements(int num) {
	for (int i = 0; i < num; ++i)
		set.push_back(-1);
}

int DisjointSets::find(int elem) {
	return set.at(elem) < 0 ? elem : set.at(elem) = find(set.at(elem));
}

void DisjointSets::setunion(int a, int b) {
	auto root1 = find(a);
	auto root2 = find(b);
	int newSize = set.at(root1) + set.at(root2);
	if (set.at(root1) < set.at(root2)) {
		set.at(root2) = root1;
		set.at(root1) = newSize;
	} else {
		set.at(root1) = root2;
		set.at(root2) = newSize;
	}
}

int DisjointSets::size(int elem) {
	return -1 * set.at(find(elem));
}
