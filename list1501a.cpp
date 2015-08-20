//
// Created by carmen on 20/08/2015.
//

#include <iostream>
#include <fstream>
#include <vector>


int main() {

    std::string word{};
    std::vector<std::string> words{};
    std::vector<int> frequency{};

    std::ifstream in{"list1501a.txt"};
    if (not in) {
        std::perror("list1501a.txt");
    } else {

        while (in >> word) {
            if (std::find)
            words.push_back(word);
            frequency.push_back(1);
        }



        // Print out results

        for (std::vector<int>::size_type i{0}, end{words.size()}; i != end; ++i) {
            std::cout << words.at(i) << ' ' << frequency.at(i) << std::endl;
        }
    }

    return 0;
}
