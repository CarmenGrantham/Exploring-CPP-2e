//
// Created by carmen on 4/08/2015.
//

#include <iostream>

int main() {
    int sum{0};
    int count{};
    int x;
    while (std::cin >> x) {
        sum = sum + x;
        count = count + 1;
    }

    if (count == 0) {
        std::cout << "cannot compute, count is zero" << '\n';
    } else {
        std::cout << "average = " << sum / count << '\n';
    }

    return 0;
};
