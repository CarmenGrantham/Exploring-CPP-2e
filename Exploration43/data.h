//
// Created by carmen on 25/09/2015.
//

#ifndef EXPLORING_CPP_2E_DATA_H
#define EXPLORING_CPP_2E_DATA_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

/// Convenient shorthand for a vector of images
typedef std::vector<int> intvector;

/// Convenient shorthand for an intvector's iterator
typedef intvector::iterator intvec_iterator;

/// Read a series of integers from the standard input into @p data,
/// overwriting @p data in the process
/// @param[in,out] data a vector of integers
inline void read_data(intvector& data) {
    data.clear();
    data.insert(data.begin(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
}

/// Write a vector of integers to the standard output. Write all values on one
/// line, separated by single space characters, and surrounded by curly braces,
/// e.g., {1, 2, 3}
/// @param data a vector of integers
inline void write_data(intvector const& data) {
    std::cout << "{ ";
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}\n";
};

#endif //EXPLORING_CPP_2E_DATA_H
