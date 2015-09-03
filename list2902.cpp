//
// Created by carmen on 1/09/2015.
//

#include <iostream>

// Represent a rational number
struct rational {
    int numerator;      ///< numerator gets the sign of the rational value
    int denominator;    ///< denominator always positive
};

int main() {
    rational pi{};
    pi.numerator = 355;
    pi.denominator = 113;
    std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << "\n";
}