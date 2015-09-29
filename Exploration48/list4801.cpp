//
// Created by carmen on 29/09/2015.
//

#include <iostream>

template<class T>
T absval(T x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main() {
    int val1{1};
    int val2{-1};
    float val3{4.56};
    std::string val4{"Hello"};

    std::cout << "absolute value of " << val1 << " is " << absval(val1) << "\n";
    std::cout << "absolute value of " << val2 << " is " << absval(val2) << "\n";
    std::cout << "absolute value of " << val3 << " is " << absval(val3) << "\n";

    // Compiler will complain about no match for operator<
    //std::cout << "absolute value of " << val4 << " is " << absval(val4) << "\n";

}