//
// Created by carmen on 4/08/2015.
//

#include <iostream>

int main() {
    std::cout << "Shape\tSides\n" << "-----\t-----\n";
    std::cout << "Square\t" << 4 << "\n" <<
                                    "Circle\t?\n"
                                    "Triangle\t" << 3 << "\n";


    // Demonstrate two concatenation techniques
    std::cout << "Hello" << " World" << '\n';
    std::cout << "Hello" " World" << '\n';
}