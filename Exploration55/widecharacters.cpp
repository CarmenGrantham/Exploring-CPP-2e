//
// Created by carmen on 5/10/2015.
//

#include <iostream>

int main() {

    wchar_t capital_a{'A'};         // The compiler automatically widens narrow characters
    std::wstring ray {L"Ray"};
    wchar_t pi_unicode{L'\x03c0'};  // if wchar_t uses a unicode encoding, such as UTF-32
    std::wstring price{L"\x20ac" L"12345"}; // Unicode euro symbol followed by 12345
                                            // must have in separate strings or else compiler will try to find
                                            // hex value for 20AC12345


    std::cout << capital_a << '\n';
    std::wcout << capital_a << '\n';
    std::wcout << ray << '\n';
    std::cout << pi_unicode << '\n';
    std::wcout << pi_unicode << '\n';
    std::wcout << price << '\n';

}