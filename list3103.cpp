//
// Created by carmen on 14/09/2015.
//

#include <ios>
#include <istream>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
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

std::istream& operator>>(std::istream& in, rational& rat) {
    int n{0};
    int d{0};
    char sep{'\0'};

    if (not (in >> n >> sep)) {
        // Error reading the numerator or the separator character
        in.setstate(std::cin.failbit);
    } else if (sep != '/') {
        // Read numerator successfully, but it  is not followed by /.
        // Push sep back into the input stream, so the next input operation will read  it.
        in.unget();
        rat.assign(n, 1);
    } else if (in >> d) {
        // Successfully read numerator, separator and denominator
        rat.assign(n, d);
    } else {
        // Error reading denominator
        in.setstate(std::cin.failbit);
    }
    return in;
}


std::ostream& operator<<(std::ostream& out, rational const& rat) {
    std::ostringstream tmp{""};
    tmp<< rat.numerator;
    if (rat.denominator != 1) {
        tmp << '/' << rat.denominator;
    }
    out << tmp.str();

    return out;
}

bool iofailure(std::istream& in) {
    return in.fail() and not in.bad();
}

int main() {
    rational r{0};

    while (std::cin) {
        if (std::cin >> r) {
            // Read succeeded, so no failure state iss set in the stream.
            std::cout << r << '\n';
        } else if (iofailure(std::cin)) {
            //Only failbit is set, meaning invalid input. Clear the state
            // and then skip the rest of the input line
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }

    if (std::cin.bad()) {
        std::cerr << "Unrecoverable input failure\n";
    }
}