//
// Created by carmen on 27/08/2015.
//
// Test words for palendrome
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>

bool non_letter(char ch) {
    return not std::isalnum(ch, std::locale());
}

char lowercase(char c) {
    return std::tolower(c, std::locale());
}

bool is_same_character(char a, char b) {
    return lowercase(a) == lowercase(b);
}

bool is_palindrome(std::string str) {

    std::string::iterator end {std::remove_if(str.begin(), str.end(), non_letter)};
    std::string reversed{str.begin(), end};
    std::reverse(reversed.begin(), reversed.end());
    return not reversed.empty() and std::equal(str.begin(), end, reversed.begin(), is_same_character);
}

int main() {
    std::locale::global(std::locale{""});
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});

    std::string s1{"eve's eve"};
    std::cout << s1 << " is a palindrome " << std::boolalpha << is_palindrome(s1) << std::endl;

    std::string s2{"not a palindrome"};
    std::cout << s2 << " is a palindrome " << std::boolalpha << is_palindrome(s2) << std::endl;

    std::string s3{"Glenelg"};
    std::cout << s3 << " is a palindrome " << std::boolalpha << is_palindrome(s3) << std::endl;

    return 0;
}


