//
// Created by carmen on 28/08/2015.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data { 10, 50, 3, 60};
    std::transform(data.begin(), data.end(), data.begin(), [](int x) { return x * 2;});
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}