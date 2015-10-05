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

/**
 * Test for non-letter
 * @param ch the character to test
 * @return true if @p ch is not a letter
 */
template<class Char>
bool non_letter(Char ch) {
    return not std::isalpha(ch, std::locale());
}

/**
 * Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
template<class Char>
char lowercase(Char c) {
    return std::tolower(c, std::locale());
}

/** Compare two characters without regard to case. */
template<class Char>
bool is_same_character(Char a, Char b) {
    return lowercase(a) == lowercase(b);
}

/**
 * Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
template<class Char, class Traits, class Allocater>
bool is_palindrome(std::basic_string<Char, Traits, Allocater> str) {
    typedef typename std::basic_string<Char, Traits, Allocater> string;
    typename string::iterator end {std::remove_if(str.begin(), str.end(), non_letter<Char>)};
    string reversed{str.begin(), end};
    std::reverse(reversed.begin(), reversed.end());
    return not reversed.empty() and std::equal(str.begin(), end, reversed.begin(), is_same_character<Char>);
}

int main() {
    std::locale::global(std::locale{""});
    std::wcout.imbue(std::locale{});

    std::string s1{"eve's eve"};
    std::cout << s1 << " is a palindrome " << std::boolalpha << is_palindrome(s1) << std::endl;

    std::string s2{"not a palindrome"};
    std::cout << s2 << " is a palindrome " << std::boolalpha << is_palindrome(s2) << std::endl;

    std::string s3{"Glenelg"};
    std::cout << s3 << " is a palindrome " << std::boolalpha << is_palindrome(s3) << std::endl;

    std::wstring s5{L"fantastic"};
    std::wcout << s5 << " is a palindrome " << std::boolalpha << is_palindrome(s5) << std::endl;

    std::wstring s6{L"is adidas i"};
    std::wcout << s6 << " is a palindrome " << std::boolalpha << is_palindrome(s6) << std::endl;

    return 0;
}


