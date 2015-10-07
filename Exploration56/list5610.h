//
// Created by carmen on 6/10/2015.
//

#ifndef EXPLORING_CPP_2E_LIST5610_H
#define EXPLORING_CPP_2E_LIST5610_H

#include <ios>              // for std::noskipws
#include <istream>          // for the >> operator
#include <sstream>          // for the istringstream
#include <string>

#include "conversion_error.hpp"

template<class T>
T from_string(std::string const& str, bool skipws = true) {
    std::istringstream in{str};
    if (not skipws) {
        in >> std::noskipws;
    }
    T result{};
    char extra;
    if (not (in >> result)) {
        throw conversion_error{str};
    } else if (in >> extra) {
        throw conversion_error{str};
    } else {
        return result;
    }
}

#endif //EXPLORING_CPP_2E_LIST5610_H
