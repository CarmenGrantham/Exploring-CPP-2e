//
// Created by carmen on 22/08/2015.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

int main() {
    typedef std::map<std::string, int> count_map;
    typedef std::string::size_type str_size;

    count_map counts{};

    std::ifstream in{"list1801.txt"};
    if (not in) {
        std::perror("list1801.txt");
    } else {

        // Read words from file and count number of times
        // each word appears
        std::string okay("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_");
        std::string word{};
        while(in >> word) {
            // Make a copy of word, keeping only characters that are okay
            std::string copy{};
            for(char ch :word) {
                if (okay.find(ch) != std::string::npos) {
                    copy.push_back(ch);
                }
            }
            if (not copy.empty()) {
                ++counts[copy];
            }
        }

        // Determine longest word
        str_size longest{0};
        for(auto pair : counts) {
            if(pair.first.size() > longest) {
                longest = pair.first.size();
            }
        }

        // For each word/count pair
        const int count_size{10};
        for (auto pair : counts) {
            std::cout << std::setw(longest) << std::left << pair.first
                    << std::setw(count_size) << std::right << pair.second << '\n';
        }
    }
    in.close();
}
