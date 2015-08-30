//
// Created by carmen on 30/08/2015.
//

#include <iostream>
#include <cassert>

int main() {
    float a{0.03F};
    float b{10.0F};
    float c{0.3F};

    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "c = " << c << std::endl;

    assert(a * b == c);
}

