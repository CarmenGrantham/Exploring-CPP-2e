//
// Created by carmen on 13/08/2015.
//

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data {};

    // Read in list of numbers
    std::copy (std::istream_iterator<int>(std::cin),
               std::istream_iterator<int>(),
               std::back_inserter(data));

    // find nonzero elements
    bool allZero = true;
    for (std::vector<int>::iterator i{data.begin()}, end{data.end()}; i != end; ++i) {
        if (*i != 0) {
            allZero = false;
        }
    }

    if (allZero) {
        std::cout << "All elements are zero";
    } else {
        std::cout << "There are non-zero elements";
    }

    return 0;


}