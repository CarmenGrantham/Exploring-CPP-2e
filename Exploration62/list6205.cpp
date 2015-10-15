//
// Created by carmen on 14/10/2015.
//

#include <iostream>
#include <string>
#include <cstddef>

std::size_t my_std_strlen(char const* str) {
    char const* start{str};                 // remember the start of the string
    while (*str != 0) {                     // while not at the end of the string
        ++str;                              // advance to the next character
    }
    return str - start;                     // compute string length by subtracting pointers;
}

int main() {

    std::size_t len{my_std_strlen("hello space rangers")};

    std::cout << "Length is " << len << '\n';
}