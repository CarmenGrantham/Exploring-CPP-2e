//
// Created by carmen on 24/09/2015.
//
#include <iostream>

int main() {
    int answer{42};             // definition of a named object, also an lvalue
    int& ref{answer};           // declaration of a reference named ref
    ref = 10;                   // changes value of answer
    std::cout << answer << "\n";

    int const& cent{ref * 10};  // declaration; must be const to initialise with expr
    std::cout << cent << "\n";
}
