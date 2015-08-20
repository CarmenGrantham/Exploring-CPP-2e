//
// Created by carmen on 20/08/2015.
//


#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::map<std::string, int> counts {};
    std::string word{};

    std::ifstream in{"explore15.txt"};
    if (not in) {
        std::perror("explore15.txt");
    } else {


        while (in >> word) {
            ++counts[word];
        }

        // get the longest word
        int longest{};
        for (auto element : counts) {
            if (element.first.length() > longest) {
                longest = element.first.length();
            }
        }


        // Print out each word/count pair
        for (auto element : counts) {
            std::cout << std::setw(longest) << std::left << element.first
                    << std::setw(5) << std::right << element.second << '\n';
        }

    }

}
