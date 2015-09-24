//
// Created by carmen on 24/09/2015.
//
#include <iostream>

int generate_id() {
    static int counter{0};
    ++counter;
    return counter;
}

int main() {
    for (int i{0}; i != 10; ++i) {
        std::cout << generate_id() << "\n";
    }
}