//
// Created by carmen on 14/09/2015.
//

#include <ostream>
#include <sstream>

std::ostream& operator<<(std::ostream& out, rational const& rat) {
    std::ostringstream temp{};
    tmp<< rat.numerator;
    if (rat.denominator != 1) {
        tmp << '/' << rat.denominator;
    }
    out << tmp.str();

    return out;
}