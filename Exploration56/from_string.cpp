//
// Created by carmen on 6/10/2015.
//

#include <ostream>          // for the << operator
#include <sstream>          // for the ostringstream
#include <string>
#include <iostream>

#include "from_string.h"


template<class T, class Char, class Traits, class Allocater>
void to_string(T const& obj, std::basic_string<Char, Traits, Allocater>& result) {
    std::basic_ostringstream<Char, Traits> out{};
    out << obj;
    result = out.str();
};

int main() {
    std::string str{};
    to_string(42, str);
    int value(from_string<int>(str));

    std::cout << "str is " << str << '\n';
    std::cout << "value is " << value << '\n';
}