//
// Created by carmen on 27/08/2015.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int descending(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> data { 10, 40, 20, 90, 5};
    std::sort(data.begin(), data.end(), descending);
    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}