//
// Created by carmen on 3/10/2015.
//
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> words{};

    std::set<std::string>::iterator hint{words.begin()};

    std::string word{};
    word = "first";
    hint = words.emplace_hint(hint, std::move(word));
    word = "second";
    hint = words.emplace_hint(hint, std::move(word));
    word = "third";
    hint = words.emplace_hint(hint, std::move(word));

    for (auto a : words) {
        std::cout << a << "\n";
    }
}
