//
// Created by carmen on 13/08/2015.
//


#include <iostream>
#include <vector>

int main() {
    std::vector<int> empty {};

    if (empty) {
        std::cout << "empty is true\n";
    } else {
        std::cout << "empty is false\n";
    }
}