//
// Created by carmen on 6/10/2015.
//

#include <fstream>
#include <ostream>
#include <stdexcept>
#include <string>

#include "debug.h"

void debug(std::string const& str) {
    std::ofstream stream{"debug.txt", std::ios_base::out | std::ios_base::app};
    if (not stream) {
        throw std::runtime_error("cannot open debug.txt");
    }
    stream.exceptions(std::ios_base::failbit);
    stream << str << '\n';
    stream.close();
}

int main() {
    debug("This is line 1");
    debug("This is line 2");
}
