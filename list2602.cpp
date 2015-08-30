//
// Created by carmen on 30/08/2015.
//

#include <iostream>
#include <limits>
#include <locale>

int main() {
    std::cout.imbue(std::locale{""});
    std::cout << std:: boolalpha;

    // Change float to double or long double to learn about these types
    typedef long double T;

    std::cout << "min=" << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max=" << std::numeric_limits<T>::max() << std::endl;
    std::cout << "IEC 60559? " << std::numeric_limits<T>::is_iec559 << std::endl;
    std::cout << "max exponent=" << std::numeric_limits<T>::max_exponent << std::endl;
    std::cout << "min exponent=" << std::numeric_limits<T>::min_exponent << std::endl;
    std::cout << "mantissa places=" << std::numeric_limits<T>::digits << std::endl;
    std::cout << "radix=" << std::numeric_limits<T>::has_infinity << std::endl;
    std::cout << "has infinity? " << std::numeric_limits<T>::has_infinity << std::endl;
    std::cout << "has quiet NaN? " << std::numeric_limits<T>::has_quiet_NaN << std::endl;
    std::cout << "has signaling NaN? " << std::numeric_limits<T>::has_signaling_NaN << std::endl;

    if(std::numeric_limits<T>::infinity()) {
        T zero{0};
        T one{1};
        T inf{std::numeric_limits<T>::infinity()};
        if (one/zero == inf) {
            std::cout << "1.0/0.0 = infinity\n";
        }
        if(inf + inf == inf) {
            std::cout << "infinity + infinity = infinity\n";
        }
    }

    if(std::numeric_limits<T>::has_quiet_NaN) {
        T zero{};
        T inf{std::numeric_limits<T>::infinity()};
        std::cout << "zero/zero = " << zero/zero << std::endl;
        std::cout << "inf/inf = " << inf/inf << std::endl;
    }

}