//
// Created by carmen on 30/08/2015.
//

#include <iostream>

// print is overloaded for signed char, short, int and long

void print(signed char value) {
    std::cout << "print(signed char = " << static_cast<int>(value) << ")\n";
}

void print(short value) {
    std::cout << "print(short = " << value << ")\n";
}

void print(int value) {
    std::cout << "print(int = " << value << ")\n";
}

void print(long value) {
    std::cout << "print(long = " << value << ")\n";
}


// guess is overloaded for bool, int and long
void guess(bool value) {
    std::cout << "guess(bool = " << value << ")\n";
}

void guess(int value) {
    std::cout << "guess(int = " << value << ")\n";
}

void guess(long value) {
    std::cout << "guess(long = " << value << ")\n";
}


// error is overloaded for bool and long
void error(bool value) {
    std::cout << "error(bool = " << value << ")\n";
}

void error(long value) {
    std::cout << "error(long = " << value << ")\n";
}


int main() {
    signed char byte{10};
    short shrt{20};
    int i{30};
    long lng{40};

    print(byte);        // print(signed char)
    print(shrt);        // print(short)
    print(i);           // print(int)
    print(lng);         // print(long)

    guess(byte);        // guess(int)
    guess(shrt);        // guess(int)
    guess(i);           // guess(int)
    guess(lng);         // guess(long)

    // can convert these values to a bool or value
    //error(byte);
    //error(shrt);
    //error(i);
    error(lng);

}