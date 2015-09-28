//
// Created by carmen on 27/09/2015.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> data { 10, 20 };
    data[5] = 0;                     // This works in my compiler, but it's undefined behaviouir
    std::cout << data[5] << '\n';

    // Example of error handling
    try {
        throw std::runtime_error("oops");
    } catch (std::runtime_error const& ex) {
        std::cerr << ex.what() << '\n';
    }
}

