//
// Created by carmen on 11/08/2015.
//

#include <iostream>

int main() {
    int x{42};

    // Show difference between prefix and postfix increment
    std::cout << "x   = " << x     << '\n';
    std::cout << "++x = " << ++x   << '\n';
    std::cout << "x   = " << x     << '\n';
    std::cout << "x++ = " << x++   << '\n';
    std::cout << "x   = " << x     << '\n';
}