//
// Created by carmen on 29/08/2015.
//

#include <vector>
#include <string>
#include <iostream>
#include <iterator>

void print(int value) {
    std::cout << value;
}

void print(int value, int width) {
    std::cout.width(width);
    std::cout << value;
}

void print(std::vector<int> numbers, int width, std::string prefix, std::string separator, std::string postfix) {
    std::cout << prefix;

    bool print_separator{false};
    for (auto num : numbers) {
        if (print_separator) {
            std::cout << separator;
        }
        print(num);
        print_separator = true;
    }

    std::cout << postfix;

}

void print(std::vector<int> numbers, std::string prefix, std::string separator, std::string postfix) {
    print(numbers, 0, prefix, separator, postfix);
}


int main() {
    std::vector<int> data { 90, 30, 20, 1000, };

    std::cout << "columnal data:\n";
    print(data, 10, "", "\n", "\n");

    std::cout << "row data:\n";
    print(data, "{", ", ", "}\n");
}