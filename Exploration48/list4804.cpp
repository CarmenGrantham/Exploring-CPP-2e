//
// Created by carmen on 29/09/2015.
//


template <class T>
T add(T lhs, T rhs) {
    return lhs(rhs);
}

int main() {

    // Without following line compiler works happily
    return add(0, 0);
}