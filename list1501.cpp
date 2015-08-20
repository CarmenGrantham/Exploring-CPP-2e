//
// Created by carmen on 20/08/2015.
//

#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main() {
    std::map<std::string, int> counts {};
    std::string word{};

    std::ifstream in{"list1501.txt"};
    if (not in) {
        std::perror("list1501.txt");
    } else {


        while (in >> word) {
            ++counts[word];
        }

        // Print out each word/count pair
        for (auto element : counts) {
            std::cout << element.first << '\t' << element.second << '\n';
        }

    }

}
