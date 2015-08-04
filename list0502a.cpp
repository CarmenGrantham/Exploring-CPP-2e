//
// Created by carmen on 4/08/2015.
//

#include <iostream>

int main() {
    std::cout << "What is your name?";
    std::string name{};
    std::cin >> name;
    std::cout << "What is your age?";
    int age{};
    std::cin >> age;
    std::cout << "Hi, " << name << " you're " << age << " years old.\n";

    return 0;
}

