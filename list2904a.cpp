//
// Created by carmen on 1/09/2015.
//

#include <cassert>
#include <cstdlib>
#include <iostream>

/// Compute the greatest common divisor of two integers, using Euclid's algorithm
int gcd(int n, int m) {
    n = std::abs(n);
    while (m != 0) {
        int tmp(n % m);
        n = m;
        m = tmp;
    }
    return n;
}

/// Represent a rational number
struct rational {
    /// Reduce the numerator and denominator by their GCD
    void reduce() {
        assert(denominator != 0);
        int div(gcd(numerator, denominator));
        numerator = numerator / div;
        denominator = denominator / div;
    }

    /// Assign a numerator and a denominator, then reduce to normal form
    /// @param n numerator
    /// @param d denominator
    /// @pre denominator > 0
    void assign(int n, int d) {
        numerator = n;
        denominator = d;
        reduce();
    }


    int numerator;      ///< numerator gets the sign of the rational value
    int denominator;    ///< denominator always positive
};

int main() {
    rational pi{};
    pi.assign(1420, 452);
    std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << "\n";
}