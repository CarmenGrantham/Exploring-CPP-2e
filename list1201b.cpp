//
// Created by carmen on 13/08/2015.
//

#include <iostream>

int main() {
    bool a{true};
    bool b{false};

    std::cout << "Is 4 = 4 (true or false)?\n";
    std::cin >> std::boolalpha >> a;

    std::cout << "Is 3 = 4 (true or false)?\n";
    std:: cin >> std::noboolalpha >> b;
    std::cout << "a = " << std::boolalpha << a << ", b = " << std::noboolalpha << b << "\n";

    return 0;
}