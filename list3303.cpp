//
// Created by carmen on 16/09/2015.
//
#include <iostream>
#include <vector>

struct point {
    double x;
    double y;
};

int main() {
    point origin{};
    point unity{};

    origin.x = 0;
    origin.y = 0;

    unity.x = 1;
    unity.y = 1;

    std::cout << "origin = (" << origin.x << ", " << origin.y << ")\n";
    std::cout << "unity = (" << unity.x << ", " << unity.y << ")\n";


    // Initialise vector with elements 10 and 0 - note the braces
    std::vector<int> ten_zeroes_not {10, 0};
    std::cout << "size is " << ten_zeroes_not.size() << std::endl;

    // Initialise vectore with 10 elements, all set to 0 - not the paranthesis
    std::vector<int> ten_zeroes (10, 0);
    std::cout << "size is " << ten_zeroes.size() << std::endl;
}
