//
// Created by carmen on 27/09/2015.
//

#include <algorithm>
#include <iostream>

#include "data.h"

int main() {
    intvector data{};
    read_data(data);
    std::sort(data.begin(), data.end());
    write_data(data);

    intvec_iterator iter{std::lower_bound(data.begin(), data.end(), 42)};
    std::cout << "Index of 42 is " << std::distance(data.begin(), iter) << '\n';

    if (iter == data.end()) {
        std::cout << "Value 42 not found\n";
    } else {
        *iter = 0;
        std::cout << "Value 42 changed to 0:\n";
        write_data(data);
    }
}
