//
// Created by carmen on 14/08/2015.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> positive_data {}, negative_data {};

    for(int x{0}; std::cin >> x;) {
        if (x < 0) {
            negative_data.push_back(x);
        } else {
            negative_data.push_back(x);
        }
    }
}