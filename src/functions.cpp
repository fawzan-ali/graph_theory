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
