//
// Created by carmen on 8/10/2015.
//

#include <iostream>

class wrapper {
public:
    wrapper(int x) : p_{new int{x}}{}
    wrapper(wrapper const& w) : p_{new int{w.value()}} {}
    ~wrapper() { delete p_; }

    // This only works if taking argument by value, not reference
    wrapper& operator=(wrapper w) {
        swap(w);
        return *this;
    }

    void swap(wrapper& w) {
        int* tmp { w.p_};
        w.p_ = p_;
        p_ = tmp;
    }
    int value() const { return *p_; }

private:
    int* p_;
};


void print(wrapper w) {
    std::cout << w.value() << '\n';
}

wrapper increment(wrapper w) {
    return wrapper(w.value() + 1);
}

int main() {
    wrapper w{42};
    print(increment(w));
}