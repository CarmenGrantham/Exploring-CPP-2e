//
// Created by carmen on 6/08/2015.
//
// Print a multiplication table for 1 to 10
//

#include <iomanip>
#include <iostream>

int main() {
    using namespace std;

    cout << setw(4) << "*|";
    for (int i{1}; i <= 10; i++) {
        cout << setw(4) << i;
    }
    cout << '\n';
    cout << "---+----------------------------------------\n";

    for (int i{1}; i <= 10; i++) {
        cout << setw(3) << i << "|";
        for (int j{1}; j <= 10; j++) {
            cout << setw(4) << i * j;
        }
        cout << '\n';
    }

    return 0;
}