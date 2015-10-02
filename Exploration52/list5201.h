//
// Created by carmen on 30/09/2015.
//

#ifndef EXPLORING_CPP_2E_LIST5201_H
#define EXPLORING_CPP_2E_LIST5201_H

namespace numeric {
    template<class T>
    class rational {
        // add content here
    };

    template<class T>
    bool operator==(rational<T> const& a, rational<T> const& b);


    template<class T>
    rational<T> operator+(rational<T> const& a, rational<T> const& b) {
        rational<T> result{a};
        result += b;
        return result;
    }
}

// Example of defining operator+ outside of namespace
template<class T, int N>
numeric::rational<T> numeric::operator+(rational<T> const& a, rational<T> const& b) {
    rational<T> result{a};
    result += b;
    return result;
}




#endif //EXPLORING_CPP_2E_LIST5201_H
