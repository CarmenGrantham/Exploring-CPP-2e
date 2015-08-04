/**
 Created by carmen on 2/08/2015.
*/

#include <iostream>
#include <limits>

int main() {
    int min{std::numeric_limits<int>::max()};
    int max{std::numeric_limits<int>::min()};
    bool any{false};
    int x;
    while (std::cin >> x)
    {
        any = true;
        if (x < min) {
            min = x;
            std::cout << "resetting min to " << min << '\n';
        }
        if (x > max)
            max = x;
    }

    if (any)
        std::cout << "min = " << min << "\nmax = " << max << '\n';

    return 0;
}
