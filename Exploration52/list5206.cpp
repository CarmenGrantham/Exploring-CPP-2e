//
// Created by carmen on 30/09/2015.
//

#include <iostream>

void print(int i) {
    std::cout << "int: " << i << "\n";
}

namespace labeled {
    void print(double d) {
        std::cout << "double: " << d << "\n";
    }
}

namespace simple {
    void print(int i) {
        std::cout << i << "\n";
    }

    void print(double d) {
        std::cout << d << "\n";
    }
}

void test_simple() {
    using namespace simple;
    //print(42);                  // Compile error: call of overloaded 'print(int)' is ambiguous
    print(3.14159);                 // find simple::print(double)
}

void test_labeled() {
    using namespace labeled;
    print(42);                      // finds ::print
    print(3.14159);                 // finds labeled::print(double)
}

int main() {
    test_simple();
    test_labeled();
}