//
// Created by carmen on 11/08/2015.
//

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data {10, 20};

    std::ostream_iterator<int> out { std::ostream_iterator<int>(std::cout, " ")};
    std::copy(data.begin(), data.end(), out);

    // decrement doesn't work for write iterator so this throws compile error
    //--out;
}