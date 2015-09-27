//
// Created by carmen on 27/09/2015.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "data.h"
#include "sequence.h"

int main() {
    intvector data(10);
    std::generate(data.begin(), data.end(), sequence{0, 2});  // fill with even numbers
    intvec_iterator iter{data.begin()};
    std::advance(iter, 4);
    std::cout << *iter << ", ";
    iter = std::prev(iter, 2);
    std::cout << *iter << "\n";
}
