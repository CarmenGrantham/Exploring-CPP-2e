//
// Created by carmen on 6/10/2015.
//

#ifndef EXPLORING_CPP_2E_LIST5611_H
#define EXPLORING_CPP_2E_LIST5611_H

#include <ostream>          // for the << operator
#include <sstream>          // for the ostringstream
#include <string>

template<class T, class Char, class Traits, class Allocater>
std::basic_string<Char, Traits, Allocater> to_string(T const& obj) {
    std::basic_ostringstream<Char, Traits> out{};
    out << obj;
    return out.str();
}

#endif //EXPLORING_CPP_2E_LIST5611_H
