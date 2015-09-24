//
// Created by carmen on 24/09/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec(10);
    int state;
    std::generate(vec.begin(), vec.end(), [&state]() { return ++state; });

    // Print out result
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
