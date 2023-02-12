#include "../includes/functions.hpp"

#include <fstream>
#include <algorithm>
#include <cstdlib>

std::vector<int> degrees(std::string &filename) {
    std::vector<int> degrees;
    std::ifstream file;
    file.open(filename);
    std::string number;
    while(std::getline(file, number, ',')){
        degrees.push_back(std::stoi(number));
    }  
    file.close();
    return degrees;
}
bool isGraphicHavel(std::vector<int> d) {
    std::sort(d.rbegin(), d.rend());
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
        for (auto i = unsigned(1); i < d.size(); ++i) {
            if (i < d_1 + 1) {
                d_prime.push_back(d.at(i) - 1);
            } else {
                d_prime.push_back(d.at(i));
            }
        }
        if (isGraphicHavel(d_prime)) {
            return true;
        }
    }
    return false;
}
unsigned min(unsigned const &first, unsigned const &second) {
    if (second < first) {
        return second;
    }
    return first;
}
bool isGraphicErdos(std::vector<int> const &d) {
    auto sum = unsigned(0);
    auto n = d.size();
    for (auto i = unsigned(0); i < n; ++i) {
        sum += abs(d.at(i));
    }
    for (auto k = unsigned(0); k < n; ++k) {
        auto LHS = unsigned(0);
        auto RHS = unsigned(0);
        for (auto i = unsigned(0); i < k; ++i) {
            LHS += abs(d.at(i));
        }
        for (auto i = k; i < n; ++i) {
            RHS += min(abs(d.at(i)), k);
        }
        RHS += k * (k + 1);
        if (LHS > RHS) {
            return false;
        }
    }
    if ((sum % 2) == 0) {
        return true;
    }
    return false;
}