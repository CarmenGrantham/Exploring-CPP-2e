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

    rational& operator+=(rational const& rhs);
    rational& operator-=(rational const& rhs);
    rational& operator/=(rational const& rhs);

    rational& operator++();
    rational& operator--();
    rational operator++(int);
    rational operator--(int);

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

rational& rational::operator+=(rational const& rhs) {
    numerator_ = numerator() * rhs.denominator() + rhs.numerator() * denominator();
    denominator_ *= rhs.denominator();
    reduce();
    return *this;
}

rational& rational::operator-=(rational const& rhs) {
    numerator_ = numerator() * rhs.denominator() - rhs.numerator() * denominator();
    denominator_ *= rhs.denominator();
    reduce();
    return *this;
}


rational& rational::operator/=(rational const& rhs) {
    if (rhs.numerator() == 0) {
        throw zero_denominator("divide by zero");
    }
    numerator_ *= rhs.denominator();
    denominator_ *= rhs.numerator();
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    reduce();
    return *this;
}

rational& rational::operator++() {
    numerator_ += denominator_;
    return *this;
}


rational& rational::operator--() {
    numerator_ -= denominator_;
    return *this;
}

rational rational::operator++(int) {
    rational result {*this};
    numerator_ += denominator_;
    return result;
}

rational rational::operator--(int) {
    rational result {*this};
    numerator_ -= denominator_;
    return result;
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

    std::cout << "test = " << rational{1, 1} << "\n";

    rational r1 = rational {100, 3};
    rational r2 = rational {9, 2};

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";
    std::cout << "r1 += r2 = " << (r1 += r2) << "\n";
    std::cout << "r1 -= r2 = " << (r1 -= r2) << "\n";
    std::cout << "r1 /= r2 = " << (r1 /= r2) << "\n";

    std::cout << "++r1 = " << ++r1 << "\n";
    std::cout << "--r1 = " << --r1 << "\n";

    std::cout << "r1++ = " << r1++ << "\n";
    std::cout << "post r++ = " << r1 << "\n";
    std::cout << "r1-- = " << r1-- << "\n";
    std::cout << "post r-- = " << r1 << "\n";
}


