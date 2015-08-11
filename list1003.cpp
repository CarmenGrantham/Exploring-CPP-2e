//
// Created by carmen on 11/08/2015.
//
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data{};   // initialise to empty

    // Read integers one at a time
    std::copy (std::istream_iterator<int>(std::cin),
            std::istream_iterator<int>(),
            std::back_inserter(data));

    // Sort the vector
    std::sort(data.begin(), data.end());

    // Print the vector, one number per line
    std::copy(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, "\n" ));

    return 0;
}