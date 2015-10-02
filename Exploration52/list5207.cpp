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
    using simple::print;
    print(42);                      // find simple::print(int)
    print(3.14159);                 // find simple::print(double)
}

void test_labeled() {
    using labeled::print;
    print(42);                      // finds labeled::print(double)

    print(3.14159);                 // finds labeled::print(double)

    using ::print;
    print(42);                      // finds ::print(int)

}

int main() {
    test_simple();
    test_labeled();
}
