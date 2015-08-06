//
// Created by carmen on 6/08/2015.
//

#include <iostream>

int main() {
    int sum{0};
    for (int i{10}; i <=20; i = i + 1) {
        sum = sum + i;
    }
    std::cout << "Sum of 10 to 20 = " << sum << '\n';

    return 0;
}