//
// Created by carmen on 24/09/2015.
//
#include <iostream>

class generate_id {
public:
    generate_id() : counter_{0} {}
    long next();

private:
    //int unused;
    short counter_;
    static short prefix_;
    static short const max_counter_ = 32767l;
};

int main() {
    generate_id gen;            // Create ID generator
    for (int i{0}; i != 10; ++i) {
        std::cout << gen.next() << "\n";
    }
}
