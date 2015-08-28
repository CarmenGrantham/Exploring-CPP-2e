//
// Created by carmen on 28/08/2015.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data { 1, 2, 3 };

    int multiplier{3};
    // auto times = [multiplier](int i) { return i * multiplier;};          // This later prints 9, 18, 27
    auto times = [&multiplier](int i) { return i * multiplier;};            // This later prints 60, 120 180
    std::transform(data.begin(), data.end(), data.begin(), times);

    multiplier = 20;
    std::transform(data.begin(), data.end(), data.begin(), times);

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
