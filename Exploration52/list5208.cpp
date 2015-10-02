//
// Created by carmen on 30/09/2015.
//
#include <iostream>

void demonstrate_using_directive() {
    using namespace std;
    typedef int ostream;
    ostream x{0};
    std::cout << x << "\n";
}

void demonstrate_using_declaration() {
    using std::ostream;
    //typedef int ostream;            // Throws compilation error - redeclaration of 'typedef int ostream' - need to use a different variable name
    //ostream x{0};
    typedef int other_ostream;
    other_ostream  x{0};
    std::cout << x << "\n";
}

int main() {
    demonstrate_using_directive();
    demonstrate_using_declaration();
}