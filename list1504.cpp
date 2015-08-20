//
// Created by carmen on 20/08/2015.
//

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>

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

        // search for number of times 'the' is found
        std::map<std::string,int>::iterator the{counts.find("the")};

        // an alternative to declaring the iterator
        // auto the{counts.find("the")};

        if (the == counts.end()) {
            std::cout << "\"the\": was not found\n";
        } else if (the->second == 1) {
            std::cout << "\"the\": occurs " << the->second << " time\n";
        } else {
            std::cout << "\"the\": occurs " << the->second << " times\n";
        }
    }

    return 0;
}

