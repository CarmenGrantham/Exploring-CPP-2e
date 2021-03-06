//
// Created by carmen on 27/09/2015.
//
#include <algorithm>
#include <cassert>
#include <iostream>

#include "data.h"
#include "sequence.h"

int main() {
    intvector data(10);
    std::generate(data.begin(), data.end(), sequence(1));
    write_data(data);                               // prints { 1 2 3 4 5 6 7 8 9 10

    intvector::iterator iter{data.begin()};
    iter = iter + 5;                                // iter is random access
    std::cout << *iter << '\n';

    intvector::reverse_iterator rev {data.rbegin()};
    std::cout << *rev << '\n';                      // prints 10
    rev = rev + 4;                                  // rev is also random access
    std::cout << *rev << '\n';                      // prints 6;
    std::cout << *rev.base() << '\n';               // prints 7
    std::cout << *data.rend().base() << '\n';       // prints 1
    assert(data.rbegin().base() == data.end());
    assert(data.rend().base() == data.begin());
}
