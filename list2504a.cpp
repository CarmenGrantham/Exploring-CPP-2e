//
// Created by carmen on 30/08/2015.
//
#include <iostream>
#include <locale>

typedef signed char byte;

void print(int value) {
    std::cout << "int = " << value << "\n";
}

void print(long value) {
    std::cout << "long = " << value << "\n";
}

void print(long long value) {
    std::cout << "long long = " << value << "\n";
}

void print(byte value) {
    std::cout << "byte = " << value << "\n";
}
void print(short value) {
    std::cout << "short = " << value << "\n";
}

int main() {
    std::cout.imbue(std::locale{""});
    print(0);
    print(0L);
    print(0LL);
    print(static_cast<short>(0));
    print(static_cast<byte>(0));
    print(static_cast<byte>(255));
    print(static_cast<short>(65535));
    print(32768);
    print(-32768);
    print(2147483647);
    print(-2147483647);
    print(2147483648);

    print(9223372036854775807);
    print(-9223372036854775807);
}
