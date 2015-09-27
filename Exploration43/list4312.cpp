//
// Created by carmen on 27/09/2015.
//
#include <algorithm>

#include "data.h"
#include "sequence.h"

/// Create vector of 100 sequential integers, then shuffle into random order
int main() {
    intvector data(100);
    std::generate(data.begin(), data.end(), sequence {1, 1});
    write_data(data);

    std::random_shuffle(data.begin(), data.end());
    write_data(data);
}


