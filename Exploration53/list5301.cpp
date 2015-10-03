//
// Created by carmen on 3/10/2015.
//

#include <array>
#include "rational.h"

namespace std {
    template<class T>
    class hash<rational<T>> {
    public:
        std::size_t operator()(rationa<T> const& r) {
            return hasher_(r.numerator() + hasher_(r.denominator));
        }
    private:
        std::hash<T> hasher_;

    };
}
