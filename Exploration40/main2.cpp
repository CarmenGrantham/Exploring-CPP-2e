//
// Created by carmen on 24/09/2015.
//
#include <iostream>
#include "generate_id2.hpp"

int main() {
    generate_id2 gen;            // Create ID generator
    for (int i{0}; i != 10; ++i) {
        std::cout << gen.next() << "\n";
    }
}
