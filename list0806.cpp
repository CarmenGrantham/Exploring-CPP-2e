//
// Created by carmen on 6/08/2015.
//

#include <iostream>

int main() {

    using namespace std;

    cout.fill('0');
    cout.width(6);
    cout << 42 << '\n';
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.width(6);
    cout << 42 << '\n';
    cout << 42 << '\n';
    cout.fill('-');
    cout.width(4);
    cout << -42 << '\n';
}
