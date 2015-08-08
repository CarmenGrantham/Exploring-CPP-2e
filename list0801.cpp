//
// Created by carmen on 6/08/2015.
//
#include <iomanip>
#include <iostream>

int main() {
    std::cout << "N   N^2    N^3\n";
    for (int i{1}; i != 21; ++i) {
        std::cout << i << "\t" << i * i << "\t" << i * i * i << '\n';
    }
}
