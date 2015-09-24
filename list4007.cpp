//
// Created by carmen on 24/09/2015.
//
#include <iostream>

int counter;

int generate_id() {
    ++counter;
    return counter;
}

int main() {
    for (int i{0}; i != 10; ++i) {
        std::cout << generate_id() << "\n";
    }
}