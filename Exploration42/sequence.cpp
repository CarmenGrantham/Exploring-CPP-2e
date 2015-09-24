//
// Created by carmen on 24/09/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "sequence.h"

int main() {
    int size{};
    std::cout << "How many integers do you want?";
    std::cin >> size;

    int first{};
    std::cout << "What is the first integer? ";
    std::cin >> first;

    int step{};
    std::cout << "What is the interval between successive integers? ";
    std::cin >> step;

    std::vector<int> data(size);
    // Generate the integers to fill the vector
    std::generate(data.begin(), data.end(), sequence(first, step));

    // Print out result
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}