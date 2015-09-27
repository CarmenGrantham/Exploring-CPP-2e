//
// Created by carmen on 26/09/2015.
//

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <vector>

#include "data.h"
#include "randomint.h"

int main() {
    intvector pi{ 3, 1, 4, 1};
    intvector data{10000};
    // The randomint functor generates random numbers in the range [0, 9].
    std::generate(data.begin(), data.end(), randomint{0,9});

    auto iter(std::search(data.begin(), data.end(), pi.begin(), pi.end()));
    if (iter == data.end()) {
        std::cout << "The integer range does not contain the digits of pi.\n";
    } else {
        std::cout << "Easy as pi: ";
        std::copy(iter, iter+pi.size(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
}