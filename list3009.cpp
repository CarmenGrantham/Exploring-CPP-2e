//
// Created by carmen on 1/09/2015.
//

#include <cassert>
#include <cstdlib>
#include <iostream>
#include "test.hpp"

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
    /// Construct a rational object, given a numerator and a denominator
    /// Always reduce to normal form
    /// @param n numerator
    /// @param d denominator
    /// @pre denominator > 0
    rational(int n, int d) : numerator{n}, denominator{d} {
        reduce();
    }

    rational(int num) : numerator{num}, denominator{1} {}

    rational(double r) : rational{static_cast<int>(r * 10000), 10000} {}

    /// Reduce the numerator and denominator by their GCD
    void reduce() {
        assert(denominator != 0);
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
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

bool operator==(rational const& a, rational const& b) {
    return a.numerator == b.numerator and a.denominator == b.denominator;
}

inline bool operator!=(rational const& a, rational const& b) {
    return not (a == b);
}

bool operator<(rational const& a, rational const& b) {
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

inline bool operator<=(rational const& a, rational const&b) {
    return not (b < a);
}

inline bool operator>(rational const& a, rational const& b) {
    return b < a;
}

inline bool operator>=(rational const& a, rational const&b) {
    return not (b > a);
}

rational operator+(rational const& lhs, rational const& rhs) {
    return rational{lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
            lhs.denominator * rhs.denominator };
}

rational operator-(rational const& r) {
    return rational{-r.numerator, r.denominator};
}

rational operator-(rational const& lhs, rational const& rhs) {
    return rational{lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                      lhs.denominator * rhs.denominator};
}

rational operator*(rational const& lhs, rational const& rhs) {
    return rational{lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator};
}

rational operator/(rational const& lhs, rational const& rhs) {
    return rational {lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator};
}

int main() {
    rational result {3 * rational{1, 3}};       // Automatically converts 3 to rational{3}
    std::cout << result.numerator << "/" << result.denominator << "\n";

    int a(3.14);      // This actually creates an int of 3
    //int b{3.14};    // This throws error - narrowing convresion of '3.1400000000001e+0' from double to int inside {}
}