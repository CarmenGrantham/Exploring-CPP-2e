//
// Created by carmen on 19/08/2015.
//

#include <cstdio>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream in{"list1401.txt"};
    if (not in) {
        std::perror("list1401.txt");
    } else {
        int x{};

        while (in >> x) {
            std::cout << x << '\n';
        }
        in.close();
    }
}