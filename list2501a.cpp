//
// Created by carmen on 2/08/2015.
//

#include <iostream>
#include <limits>

int main() {
    // Not that 'digits' means binary digits, ie. bits
    int size{std::numeric_limits<int>::digits};
    if (std::numeric_limits<int>::is_signed) {
        size = size + 1;
    }
    std::cout << "bits per int: " << size << '\n';


    int bool_size{std::numeric_limits<bool>::digits};
    if (std::numeric_limits<bool>::is_signed) {
        bool_size = bool_size + 1;
    }
    std::cout << "bits per bool: " << bool_size << '\n';


    int long_size{std::numeric_limits<long>::digits};
    if (std::numeric_limits<long>::is_signed) {
        long_size = long_size + 1;
    }
    std::cout << "bits per long: " << long_size << '\n';


    int short_size{std::numeric_limits<short>::digits};
    if (std::numeric_limits<short>::is_signed) {
        short_size = short_size + 1;
    }
    std::cout << "bits per short: " << short_size << '\n';


    int long_long_size{std::numeric_limits<long long>::digits};
    if (std::numeric_limits<long long>::is_signed) {
        long_long_size = long_long_size + 1;
    }
    std::cout << "bits per bool: " << long_long_size << '\n';
}