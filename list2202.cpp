//
// Created by carmen on 27/08/2015.
//

#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <fstream>

typedef std::map<std::string, int>  count_map;      // Map words to count
typedef count_map::value_type       count_pair;     // Pair of a word and a count
typedef std::string::size_type      str_size;       // String size type

void initialise_streams() {
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});
}

str_size get_longest_key(count_map const& map) {
    str_size result {0};
    for (auto pair : map) {
        if (pair.first.size() > result) {
            result = pair.first.size();
        }
    }
    return result;
}

void print_pair(count_pair const& pair, str_size longest) {
    int const count_size{10};
    std::cout << std::setw(longest) << std::left << pair.first <<
                 std::setw(count_size) << std::right << pair.second << "\n";
}

void print_counts(count_map counts) {
    str_size longest{get_longest_key(counts)};

    for (count_pair pair : counts) {
        print_pair(pair, longest);
    }
}

std::string sanitize(std::string const& str) {
    std::string result{};
    for (char c : str) {
        if(std::isalnum(c, std::locale{})) {
            result.push_back(std::tolower(c, std::locale{}));
        }
    }
    return result;
}

int main() {

    std::ifstream in{"list2202.txt"};
    if (not in) {
        std::perror("list2202.txt");
    } else {


        std::locale::global(std::locale{""});
        initialise_streams();

        count_map counts{};

        std::string word{};
        while (in >> word) {
            std::string copy(sanitize(word));

            if(not copy.empty()) {
                ++counts[copy];
            }
        }
        print_counts(counts);
    }
    in.close();

}