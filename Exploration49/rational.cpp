//
// Created by carmen on 29/09/2015.
//

#include <iostream>
#include <sstream>

#include "rational.h"

template<class T>
int gcd(T n, T m) {
    n = std::abs(n);
    while (m != 0) {
        int tmp(n % m);
        n = m;
        m = tmp;
    }
    return n;
}

template<class T>
void rational<T>::reduce() {
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div{gcd(numerator_, denominator_)};
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
}

template<class T>
std::istream& operator>>(std::istream& in, rational<T>& rat) {
    T n{}, d{};
    char sep{};
    if (not (in >> n >> sep))
        // Error reading the numerator or the separator character.
        in.setstate(in.failbit);
    else if (sep != '/')
    {
        // Push sep back into the input stream, so the next input operation
        // will read it.
        in.unget();
        rat.assign(n, 1);
    }
    else if (in >> d)
        // Successfully read numerator, separator, and denominator.
        rat.assign(n, d);
    else
        // Error reading denominator.
        in.setstate(in.failbit);

    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, rational<T> const& r) {
    std::ostringstream tmp{};
    tmp << r.numerator() << '/' << r.denominator();
    out << tmp.str();

    return out;
}

int main() {
    // Using an int
//    rational<int> r{};
//    while(std::cin >> r) {
//        std::cout << r << "\n";
//    }

    // Now as a long, it works just as well
//    rational<long> r{};
//    while(std::cin >> r) {
//        std::cout << r << "\n";
//    }

    // Show how long causes problems
    rational<long> r1 {45};
    rational<long> r2 {340};
    std::cout << "checking for inequality " << (r1 != r2) << "\n"; // Causes compile error when there is operator!=(rational<T> const&, T) and operator!=(T, rational<T> const&)
}
