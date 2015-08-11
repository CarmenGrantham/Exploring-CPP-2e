//
// Created by carmen on 11/08/2015.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>

int main() {
    std::vector<int> data {};

    // Read integers one at a time from user input
    std::copy (std::istream_iterator<int>(std::cin),
               std::istream_iterator<int>(),
               std::back_inserter(data));

    // Print each number, it doubled and squared on each line
    for (std::vector<int>::iterator i{data.begin()}, end{data.end()}; i != end; ++i) {
        std::cout << std::setw(4) << *i <<
                std::setw(4) << *i * 2 <<
                std::setw(4) << *i * *i << '\n';
    }
    return 0;
}