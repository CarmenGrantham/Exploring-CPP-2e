//
// Created by carmen on 26/09/2015.
//

#include <algorithm>
#include <iostream>

#include "data.h"
#include "intrange.h"

int main() {
    intvector data{};
    read_data(data);
    write_data(data);
    auto iter(std::find_if(data.begin(), data.end(), intrange{10, 20}));
    if (iter == data.end()) {
        std::cout << "No values in [10, 20] not found\n";
    } else {
        std::cout << "Value " << *iter << " in range [10,20]\n";
    }
}