//
// Created by carmen on 29/09/2015.
//

#include <iostream>

template<class T>
T min(T a, T b) {
    if (a < b) {
        return a;
    } else if (b < a) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int x{4};
    long y{10};

    //std::cout << std::min(x,y) << "\n";         // Raises error no matching function for call to min(int&, long int&);
    std::cout << std::min<long>(x,y) << "\n";
}