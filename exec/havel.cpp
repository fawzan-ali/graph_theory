#include "../includes/functions.hpp"

#include <iostream>

//checks if a sequence is graphic using the Havel-Hakimi algorithm
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments.\nUsage: " << argv[0] <<  " <filename>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::vector<int> sequence = degrees(filename);
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