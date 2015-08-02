//
// Created by carmen on 2/08/2015.
//

#include <iostream>
#include <limits>

int main() {
    // Not that 'digits' means binary digits, ie. bits
    std::cout << "bits per bool: " << std::numeric_limits<bool>::digits << '\n';
}