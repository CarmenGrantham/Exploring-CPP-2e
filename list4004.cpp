//
// Created by carmen on 24/09/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

int main() {
    std::vector<int> data { 35, 39, 100, 42, 1, 55, 1000, 3344, 42};
    std::sort(data.begin(), data.end());
    // find all values equal to 42
    auto const& range( std::equal_range(data.begin(), data.end(), 42));
    if (range.first != range.second) {
        // Print the range indices only if at least one value is found
        std::cout << "index of start of range: " << range.first - data.begin() << "\n";
        std::cout << "index of end of range: " << range.second - data.begin() << "\n";
    }
    std::cout << "size of range:           " << range.second - range.first << "\n";
}
