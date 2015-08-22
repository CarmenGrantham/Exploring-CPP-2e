//
// Created by carmen on 22/08/2015.
//

#include <iostream>

int main() {
    int sum{0};
    int x{};

    while (std::cin >> x) {
        sum += x;
    }

    std::cout << "Sum is " << sum;
}