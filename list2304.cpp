//
// Created by carmen on 28/08/2015.
//

#include <iostream>

int main() {
    int x{0};
    auto lambda = [x](int y) {
        x = 1;
        y = 2;
        return x + y;
    };
    int local{0};
    std::cout << lambda(local) << ", " << x << ", " << local << "\n";
}