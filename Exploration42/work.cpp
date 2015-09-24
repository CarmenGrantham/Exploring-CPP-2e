//
// Created by carmen on 24/09/2015.
//

#include <iostream>

#include "generate_id.h"
#include "library.hpp"

bool get_movie(std::string& title, int& runtime) {
    std::cout << "Movie title: ";
    if (not std::getline(std::cin, title)) {
        return false;
    }
    std::cout << "Runtime (minutes): ";
    if (not (std::cin, runtime)) {
        return false;
    }
    return true;
}

int main() {
    generate_id gen{};
    std::string title{};
    int runtime{};
    while(get_movie(title, runtime)) {
        movie m(int_to_id(gen()), title, runtime);
        accession(m);
    }
}