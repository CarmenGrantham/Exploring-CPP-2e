//
// Created by carmen on 27/08/2015.
//
// Rewrite print_vector to pass by value and use const reference

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void modify(int& x) {
    x = 10;
}

int triple(int const& x) {
    return 3 * x;
}

void print_vector(std::vector<int> const& v) {
    std::cout << "{ ";
    // v.push_back(9000);           // Adding this line throws compile error

    //std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    // Example using const_iterator
    std::string separator{};
    for(std::vector<int>::const_iterator i{v.begin()}, end {v.end()} ; i != end; ++i) {
        std::cout << separator << *i;
        separator = ", ";
    }

    std::cout << "}\n";
}

void add(std::vector<int>& v, int a) {
    for(auto iter(v.begin()), end(v.end()); iter != end; ++iter) {
        *iter = *iter + a;
    }
}

int main() {
    int a{42};
    modify(a);
    std::cout << "a=" << a << "\n";

    int b{triple(14)};
    std::cout << "b=" << b << "\n";

    std::vector<int> data{ 10, 20, 30, 40 };

    print_vector(data);
    add(data, 42);
    print_vector(data);

    return 0;
}