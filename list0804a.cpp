//
// Created by carmen on 6/08/2015.
//
#include <iomanip>
#include <iostream>

int main() {
    using namespace std;
    cout << setfill('0') << setw(6) << 42 << '\n';
    cout << left         << setw(6) << 42 << '\n';
    cout                            << 42 << '\n';
    cout << setfill('-') << setw(4) << -42 << '\n';
}

