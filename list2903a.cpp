//
// Created by carmen on 30/08/2015.
//
#include<iostream>


void print(float value, int precision) {
    std::cout.precision(precision);

    std::cout << value << " scientific= " << std::scientific << value
            << "\t fixed = " << std::fixed << value
            << "\t hexfloat = " << std::hexfloat << value;
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "\t general = " << value << std::endl;
}

int main() {
    print(123456.789, 6);
    print(1.23456789, 4);
    print(123456789, 2);
    print(-1234.5678e9, 5);
}
