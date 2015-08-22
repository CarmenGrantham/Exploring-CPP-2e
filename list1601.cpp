//
// Created by carmen on 21/08/2015.
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> counts{};
    typedef std::map<std::string, int> count_map;
    typedef count_map::iterator count_iterator;

    // Read words from file and count number of times each word occurs


    std::ifstream in{"explore16.txt"};
    if (not in) {
        std::perror("explore16.txt");
    } else {
        std::string word{};
        while (in >> word) {
            ++counts[word];
        }

        count_iterator the{counts.find("the")};

        if (the == counts.end()) {
            std::cout << "\"the\": was not found\n";
        } else if (the->second == 1) {
            std::cout << "\"the\": occurs " << the->second << " time\n";
        } else {
            std::cout << "\"the\": occurs " << the->second << " times\n";
        }
    }
}