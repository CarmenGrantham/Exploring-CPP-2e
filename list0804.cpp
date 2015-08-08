//
// Created by carmen on 6/08/2015.
//
#include <iomanip>
#include <iostream>

int main() {
    using namespace std;
    cout << '|' << setfill('*') << setw(6) << 1234 << '|' << '\n';
    cout << '|' << left         << setw(6) << 1234 << '|' << '\n';
    cout << '|' <<                 setw(6) << -1234 << '|' << '\n';
    cout << '|' << right        << setw(6) << -1234 << '|' << '\n';
}
