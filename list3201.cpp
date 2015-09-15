//
// Created by carmen on 15/09/2015.
//

#include <ios>
#include <istream>
#include <sstream>
#include <cassert>
#include <cstdlib>

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

    rational& operator=(rational const& rhs) {
        numerator = rhs.numerator;
        denominator = rhs.numerator;
        reduce();
        return *this;
    }

    int numerator;      ///< numerator gets the sign of the rational value
    int denominator;    ///< denominator always positive
};


