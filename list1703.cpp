//
// Created by carmen on 21/08/2015.
//

#include <iostream>
#include <vector>

int main() {
    typedef std::vector<int> intvec;
    typedef intvec::iterator iterator;

    intvec xs{};
    intvec ys{};

    {
        int x{};
        int y{};
        char sep{};
        while (std::cin >> x >> sep and sep == ',' and std::cin >> y) {
            xs.push_back(x);
            ys.push_back(y);
        }
    }

    for (iterator x{xs.begin()}, y{ys.begin()}; x != xs.end(); ++x, ++y) {
        std::cout << *x << ',' << *y << '\n';
    }

    return 0;
}