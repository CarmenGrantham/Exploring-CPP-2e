//
// Created by carmen on 14/10/2015.
//

#include <iostream>

int main(int argc, char* argv[]) {
    char const* separator{""};
    while (--argc != 0) {
        std::cout << separator << *++argv;
        separator = " ";
    }
}
