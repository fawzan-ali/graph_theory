#include "../includes/functions.hpp"

#include <iostream>

int main() {
    std::vector<int> sequence = {1,2,3,4,5,6,7,8,9,9,9,9,9,9};
    if (sequence.at(0) >= sequence.size()) {
        std::cout << "Sequence is not graphic." << std::endl;
        return 0;
    }
    if (isGraphicHavel(sequence)) {
        std::cout << "Sequence is graphic." << std::endl;
    } else {
        std::cout << "Sequence is not graphic." << std::endl;
    }
    return 0;
}
