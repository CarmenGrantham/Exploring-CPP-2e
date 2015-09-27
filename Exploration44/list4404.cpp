//
// Created by carmen on 27/09/2015.
//
#include <iostream>

#include "data.h"

int main() {
    intvector data{};
    read_data(data);
    intvector::const_iterator iter{data.begin()};
    std::advance(iter, data.size() / 2);                // move to middle of vector
    if (not data.empty()) {
        std::cout << "middle item = " << *iter << "\n";
        //*iter = 100;             // Compiler throws error about assigning to read-only location, changing iter to iterator this line works
    }
    write_data(data);
}
