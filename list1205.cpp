//
// Created by carmen on 13/08/2015.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> a {10, 20, 30};
    std::vector<int> b {10, 20, 30};

    if (a != b) std::cout << "wrong: a != b\n";
    if (a <  b) std::cout << "wrong: a < b\n";
    if (a > b)  std::cout << "wrong: a  > b\n";
    if (a == b) std::cout << "okay: a == b\n";
    if (a >= b) std::cout << "okay: a >= b\n";
    if (a <= b) std::cout << "okay: a <= b\n";


    a.push_back(40);
    if (a != b) std::cout << "okay: a != b\n";
    if (a <  b) std::cout << "wrong: a < b\n";
    if (a > b)  std::cout << "okay: a  > b\n";
    if (a == b) std::cout << "wrong: a == b\n";
    if (a >= b) std::cout << "okay: a >= b\n";
    if (a <= b) std::cout << "wrong: a <= b\n";


    b.push_back(42);
    if (a != b) std::cout << "okay: a != b\n";
    if (a <  b) std::cout << "okay: a < b\n";
    if (a > b)  std::cout << "wrong: a  > b\n";
    if (a == b) std::cout << "wrong: a == b\n";
    if (a >= b) std::cout << "wrong: a >= b\n";
    if (a <= b) std::cout << "okay: a <= b\n";

}