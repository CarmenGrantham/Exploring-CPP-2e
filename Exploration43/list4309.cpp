//
// Created by carmen on 27/09/2015.
//
#include <algorithm>
#include <iostream>
#include <vector>

#include "data.h"

int main() {
    //intvector data1 { 10, 30, 50, 2, 100, 34};
    //intvector data2 { 10, 34, 10};

    //intvector data1 { 10, 30, 50, 2, 100, 34};
    //intvector data2 { 10, 30, 50, 2, 100, 34};

    intvector data1 { 1, 58, 50, 20, 90, 16};
    intvector data2 { 10, 30, 50, 2, 100, 34};

    std::cout << "data1: ";
    write_data(data1);
    std::cout << "data2: ";
    write_data(data2);

    // Can do addition with vector's iterator, adding value to data1.begin offsets iterator as though you have advanced
    // number of positions returned by std::min
    auto data1_end(data1.begin() + std::min(data1.size(), data2.size()));

    std::cout << std::boolalpha;
    std::cout << "equal(data1, data2) = " << equal(data1.begin(), data1_end, data2.begin()) << '\n';

    auto result(mismatch(data1.begin(), data1_end, data2.begin()));
    std::cout << "mismatch(data1, data2) = index " << std::distance(data1.begin(), result.first) << '\n';

    std::cout << "lex_comp(data1, data2) = index " << std::lexicographical_compare(data1.begin(), data1.end(), data2.begin(), data2.end()) << '\n';
}

