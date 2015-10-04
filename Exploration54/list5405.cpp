//
// Created by carmen on 4/10/2015.
//
#include <algorithm>
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

bool non_letter(char ch) {
    return not std::isalnum(ch, std::locale());
}

char lowercase(char c) {
    return std::tolower(c, std::locale());
}

class function {
public:
    function(std::locale loc) : ctype_{std::use_facet<std::ctype<char>>(loc)}{}
    bool isalnum(char ch) const { return ctype_.is(std::ctype_base::alnum, ch);}
    char tolower(char ch) const { return ctype_.tolower(ch); }

private:
    std::ctype<char> const& ctype_;
};

class sanitizer : public function {
public:
    typedef std::string argument_type;
    typedef std::string result_type;
    sanitizer(std::locale loc) : function{loc} {}
    std::string operator()(std::string const& str) {
        std::string result{};
        for(char c : str) {
            if (isalnum(c)) {
                result.push_back(tolower(c));
            }
        }
        return result;
    }
};


int main() {


    std::ifstream in{"list2202.txt"};
    if (not in) {
        std::perror("list2202.txt");
    } else {

        // Set the global locale to the native locale
        std::locale::global(std::locale{""});
        initialise_streams();

        count_map counts{};

        std::string word{};
        sanitizer sanitize{std::locale{}};
        while (in >> word) {
            std::string copy(sanitize(word));

            if(not copy.empty()) {
                ++counts[copy];
            }
        }
        print_counts(counts);
    }
    in.close();

    return 0;
}
