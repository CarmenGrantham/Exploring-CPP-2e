//
// Created by carmen on 27/09/2015.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> data { 10, 20 };
    data.at(5) = 0;                     // Throws out of range error
    std::cout << data.at(5) << '\n';
}
