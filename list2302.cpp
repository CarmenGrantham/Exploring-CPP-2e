//
// Created by carmen on 28/08/2015.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data {34, 13, 20, 15 };
    int multiplier{3};

    std::transform(data.begin(), data.end(), data.begin(), [multiplier](int i) { return i * multiplier;});
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}