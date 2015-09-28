//
// Created by carmen on 28/09/2015.
//
#include <iostream>
#include <cassert>
#include <sstream>
#include <ostream>

class rational {
public:
    class zero_denominator : public std::logic_error {
    public:
        zero_denominator(std::string const& what_arg) : logic_error{what_arg} {}
    };
    rational();
    rational(int num);
    rational(int num, int den);
    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }

    // Some useful constants
    static const rational zero;
    static const rational one;
    static const rational pi;

private:
    void reduce();
    int numerator_;
    int denominator_;
};

rational::rational() : rational{0} {}
rational::rational(int num) : numerator_{num}, denominator_{1} {}
rational::rational(int num, int den) : numerator_{num}, denominator_{den} {
    if (denominator_ == 0) {
        throw zero_denominator{"zero denominator"};
    }
    reduce();
}

std::ostream& operator<<(std::ostream& out, rational const& r) {
    std::ostringstream tmp{};
    tmp << r.numerator() << '/' << r.denominator();
    out << tmp.str();

    return out;
}

int gcd(int n, int m) {
    n = std::abs(n);
    while (m != 0) {
        int tmp(n % m);
        n = m;
        m = tmp;
    }
    return n;
}

const rational rational::zero{};
const rational rational::one{1};
const rational rational::pi{355, 113};

void rational::reduce() {
    if (denominator_ == 0) {
        throw new zero_denominator{"denominator is zero"};
    }
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div{gcd(numerator_, denominator_)};
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
}



int main() {
    std::cout << "pi = " << rational::pi << "\n";

    std::cout << "zero = " << rational{1, 0} << "\n";
}

