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

        std::ofstream out{"list1402.txt"};
        if (not out) {
            std::perror("list1402.txt");
        } else {
            int x{};
            while (in >> x) {
                while (in >> x) {
                    out << x << '\n';
                }
            }
        }
        out.close();
        if (not out) {
            std::perror("list1402.txt");
        }
    }
    in.close();

    return 0;
}