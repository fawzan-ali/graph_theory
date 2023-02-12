#include "../includes/utilities.hpp"

unsigned min(unsigned const &first, unsigned const &second) {
    if (second < first) {
        return second;
    }
    return first;
}