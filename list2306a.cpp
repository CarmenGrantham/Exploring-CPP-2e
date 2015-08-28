//
// Created by carmen on 28/08/2015.
//


#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>


bool is_palindrome(std::string str) {

    std::string::iterator end {std::remove_if(str.begin(), str.end(), [](char ch) { return not std::isalnum(ch, std::locale()); })};
    std::string reversed{str.begin(), end};
    std::reverse(reversed.begin(), reversed.end());

    return not reversed.empty() and std::equal(str.begin(), end, reversed.begin(), [](char a, char b) {
        auto lowercase = [](char c) { return std::tolower(c, std::locale()); };
        return lowercase(a) == lowercase(b);
    } );
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


