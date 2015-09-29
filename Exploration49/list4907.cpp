//
// Created by carmen on 29/09/2015.
//
#include "rational.h"


int main() {
    rational<int> little{};
    rational<long> big{};
    big = little;       // Throws compiler error when there isn't an 'operator=' declared in class rational
}
