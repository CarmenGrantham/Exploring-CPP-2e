//
// Created by carmen on 27/09/2015.
//

#include <algorithm>
#include <iostream>
#include <vector>

#include "data.h"

int main() {
    intvector data{ 10, 30, 50, 2, 100, 34};
    std::sort(data.begin(), data.end());
    write_data(data);

    std::cin.clear();
    int test{};
    while (std::cin >> test) {
        intvec_iterator lb{std::lower_bound(data.begin(), data.end(), test)};
        intvec_iterator ub{std::lower_bound(data.begin(), data.end(), test)};

        std::cout << "lower bound = " << std::distance(data.begin(), lb) << '\n';
        std::cout << "upper bound = " << std::distance(data.begin(), ub) << '\n';
    }
}

