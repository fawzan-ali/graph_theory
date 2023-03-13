#include "../includes/functions.hpp"

#include <iostream>

int main() {
//	std::vector<int> sequence = {1,2,3,4,5,6,7,8,9,9,9,9,9,9};
//    	if (isGraphicHavel(sequence)) {
//        	std::cout << "Sequence is graphic." << std::endl;
//    	} else {
//        	std::cout << "Sequence is not graphic." << std::endl;
//      }
//	std::vector<int> prufer = {3,0,3,4};
//	std::vector<std::vector<int>> tree = PruferToAdjacencyMatrix(prufer);
//	for (unsigned int i = 0; i < tree.size(); ++i) {
//		for (unsigned int j = 0; j < tree.at(i).size(); ++j) {
//			std::cout << tree.at(i).at(j) << " ";
//		}
//		std::cout << std::endl;
//	}
	std::vector<int> vec0 = {3};
	std::vector<int> vec1 = {3};
	std::vector<int> vec2 = {3};
	std::vector<int> vec3 = {0,1,2,4};
	std::vector<int> vec4 = {3,5};
	std::vector<int> vec5 = {4};

	std::vector<std::vector<int>> adjacency_list = {vec0, vec1, vec2, vec3, vec4, vec5};

	std::vector<int> prufer_code = AdjacencyListToPrufer(adjacency_list);

	for (unsigned int i = 0; i < prufer_code.size(); ++i) {
		std::cout << prufer_code.at(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}
