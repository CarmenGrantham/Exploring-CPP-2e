//
// Created by carmen on 25/09/2015.
//

#include <algorithm>
#include <iostream>

#include "data.h"

int main() {
    intvector data{};
    read_data(data);
    write_data(data);
    auto iter(std::find(data.begin(), data.end(), 42));
    if (iter == data.end()) {
        std::cout << "Value 42 not found\n";
    } else {
        *iter = 0;
        std::cout << "Value 42 changed to 0:\n";
        write_data(data);
    }
}