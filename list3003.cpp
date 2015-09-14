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

int main() {
    rational a{60, 5};
    rational b{12, 1};
    rational c{-24, -2};

    TEST(a == b);
    TEST(a >= b);
    TEST(a <= b);
    TEST(b <= a);
    TEST(b >= a);
    TEST(b == a);
    TEST(b == c);
    TEST(b >= c);
    TEST(b <= c);
    TEST(a == c);
    TEST(a >= c);
    TEST(a <= c);

    rational d{109, 10};
    TEST(d < a);
    TEST(d <= a);
    TEST(d != a);
    TEST(a > d);
    TEST(a >= d);
    TEST(a != d);

    rational e{241, 20};
    TEST(e > a);
    TEST(e >= a);
    TEST(e != a);
    TEST(a < e);
    TEST(a <= e);
    TEST(a != e);

}