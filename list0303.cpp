//
// Created by carmen on 4/08/2015.
//

#include <iostream>

int main() {
    int sum{0};
    int count{};
    int x;
    while (std::cin >> x) {
        if (x % 2 == 0) {
            std::cout << x << " is even.\n";
        } else {
            std::cout << x << " is odd.\n";
        }
    }
};
