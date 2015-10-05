//
// Created by carmen on 5/10/2015.
//


#include <iostream>
#include <limits>
#include <cwchar>

int main() {

    int char_size{std::numeric_limits<char>::digits};
    std::cout << "bits per char: " << char_size << '\n';

    int wchar_t_size{std::numeric_limits<wchar_t>::digits};
    std::cout << "bits per wchar_t: " << wchar_t_size << '\n';

    int wint_t_size{std::numeric_limits<std::wint_t>::digits};
    std::cout << "bits per wint_t: " << wint_t_size << '\n';
}