//
// Created by carmen on 6/10/2015.
//

#ifndef EXPLORING_CPP_2E_LIST5690_H
#define EXPLORING_CPP_2E_LIST5690_H

#include <istream>          // for the >> operator
#include <sstream>          // for the istringstream
#include <string>

#include "conversion_error.hpp"

template<class T>
T from_string(std::string const& str) {
    std::istringstream in{str};
    T result{};
    if (in >> result) {
        return result;
    } else {
        return conversion_error{str};
    }
}
#endif //EXPLORING_CPP_2E_LIST5690_H
