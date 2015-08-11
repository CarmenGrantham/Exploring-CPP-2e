//
// Created by carmen on 11/08/2015.
//
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> data{};   // initialise to empty
    int x{};

    // Read integers one at a time
    while (std::cin >> x) {
        // Store each integer in the vector
        data.push_back(x);
    }

    // Sort the vector
    std::sort(data.begin(), data.end());

    // Print the vector, one number per line - using iterator
    for (std::vector<int>::iterator i{data.begin()}, end{data.end()}; i != end; ++i) {
        std::cout << *i << '\n';
    }

    return 0;
}