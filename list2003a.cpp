//
// Rewrite word counting program with functions
//
// Created by carmen on 25/08/2015.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <fstream>

typedef std::map<std::string, int> count_map;
typedef std::string::size_type str_size;

void initialiseStreams(std::locale loc) {
    std::cin.imbue(loc);
    std::cout.imbue(loc);

}
std::string readWord(std::string value, std::locale loc) {

    std::string word{};
    for(char ch :value) {
        if (std::isalnum(ch, loc)) {
            word.push_back(tolower(ch, loc));
        }
    }

    return word;
};

std::string::size_type getLongestWord(std::map<std::string, int> counts) {
    str_size longest{};
    for(auto pair : counts) {
        if(pair.first.size() > longest) {
            longest = pair.first.size();
        }
    }
    return longest;
}

void printWords(std::map<std::string, int> counts) {

    // Determine longest word
    std::string::size_type longest{getLongestWord(counts)};

    const int count_size{10};
    for (auto pair : counts) {
        std::cout << std::setw(longest) << std::left << pair.first
        << std::setw(count_size) << std::right << pair.second << '\n';
    }

}

int main() {

    std::locale native{""};

    initialiseStreams(native);


    std::ifstream in{"list1901a.txt"};
    if (not in) {
        std::perror("list1901a.txt");
    } else {
        count_map counts{};

        // Read words from file and count number of times
        // each word appears
        std::string word{};
        while(in >> word) {
            // Make a copy of word, keeping only characters that are okay
            std::string copy{readWord(word, native)};
            if (not copy.empty()) {
                ++counts[copy];
            }
        }

        // For each word/count pair
        printWords(counts);
    }
    in.close();

    return 0;
}


