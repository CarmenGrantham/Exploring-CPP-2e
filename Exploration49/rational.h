//
// Created by carmen on 29/09/2015.
//

#ifndef EXPLORING_CPP_2E_RATIONAL_H
#define EXPLORING_CPP_2E_RATIONAL_H

#include <cassert>
#include <cstdlib>

/// Compute the greatest common divisor of two integers, using Euclid’s algorithm.
int gcd(int n, int m)
{
    n = std::abs(n);
    while (m != 0) {
        int tmp(n % m);
        n = m;
        m = tmp;
    }
    return n;
}

template<class T>
class rational {
public:
    typedef T value_type;
    rational() : rational{0} {};
    rational(T num) : numerator_{num}, denominator_{1} {}
    rational(T num, T den);

    void assign(T num, T den);

    template<class U>
    U convert() const {
        return static_cast<U>(numerator()) / static_cast<U>(denominator());
    }

    T numerator() const { return numerator_; }
    T denominator() const { return denominator_; }


    template<class U>
    rational<T>& operator=(rational<U> const& rhs) {
        assign(rhs.numerator(), rhs.denominator());
        return *this;
    }


private:
    void reduce();
    T numerator_;
    T denominator_;
};

template<class T>
rational<T>::rational(T num, T den) : numerator_{num}, denominator_{den} {
    reduce();
}

template<class T>
void rational<T>::assign(T num, T den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

template<class T>
bool operator==(rational<T> const& a, rational<T> const& b) {
    return a.numerator() == b.numerator() and
           a.denominator() == b.denominator();
}

// Causes problems when using long type
//template<class T>
//inline bool operator!=(rational<T> const& a, T b) {
//    return not (a == b);
//}
//
//template<class T>
//inline bool operator!=(T a, rational<T> const& b) {
//    return not (a == b);
//}

template<class T>
bool operator!=(rational<T> const& a, rational<T> const& b) {
    return not (a == b);
}

template<class T>
bool operator!=(rational<T> const& a, T const& b) {
    return not (a == b);
}

template<class T>
bool operator!=(T const& a, rational<T> const& b) {
    return not (a == b);
}

template<class T>
void rational<T>::reduce()
{
    assert(denominator() != 0);
    if (denominator() < 0)
    {
        denominator_ = -denominator();
        numerator_ = -numerator();
    }
    int div{gcd(numerator(), denominator())};
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
}

#endif //EXPLORING_CPP_2E_RATIONAL_H
