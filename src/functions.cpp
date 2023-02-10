#include "../includes/functions.hpp"

#include <fstream>
#include <bits/stdc++.h>

std::vector<int> degrees(std::string filename) {
    std::vector<int> degrees;
    std::ifstream file;
    file.open(filename);
    std::string number;
    while(std::getline(file, number, ',')){
        degrees.push_back(std::stoi(number));
    }  
    file.close();
    std::sort(degrees.rbegin(), degrees.rend());
    return degrees;
}
bool isGraphicHavel(std::vector<int> d) {
    auto d_1 = d.at(0);
    auto d_n = d.at(d.size() - 1);
    if (d_n < 0) {
        return false;
    }
    if (d_1 == 0) {
        return true;
    }
    std::vector<int> d_prime;
    if (d.size() > 1) {
        for (int i = 1; i < d.size(); ++i) {
            if (i < d_1 + 1) {
                d_prime.push_back(d.at(i) - 1);
            } else {
                d_prime.push_back(d.at(i));
            }
        }
        std::sort(d_prime.rbegin(), d_prime.rend());
        if (isGraphicHavel(d_prime)) {
            return true;
        }
    }
    return false;
}