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

    float as_float() {
        return static_cast<float>(numerator) / denominator;
    }

    double as_double() {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    long double as_long_double() {
        return static_cast<long double>(numerator) / static_cast<long double>(denominator);
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

rational absval(rational const& r) {
    return rational(std::abs(r.numerator), r.denominator);
}

int main() {
    rational pi{355, 113};
    rational bmi{90 * 100 * 100, 180*180};      // body mass index of 90kg, 180cm
    double circumference{0};
    double radius{10};

    circumference = 2 * pi.as_double() * radius;
    std::cout << "circumference of circle with radius " << radius << " is about " << circumference << "\n";
    std::cout << "bmi = " << bmi.as_float() << "\n";
}