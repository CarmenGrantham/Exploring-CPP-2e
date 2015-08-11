//
// Created by carmen on 11/08/2015.
//
#include <iostream>
#include <algorithm>

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

    // Print the vector, one number per line
    for (std::vector<int>::size_type i{0}, end{data.size()}; i != end; ++i) {
        std::cout << data.at(i) << '\n';
    }

    return 0;
}