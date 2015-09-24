//
// Created by carmen on 24/09/2015.
//
#include <iostream>

class generate_id {
public:
    generate_id() : counter_{0} {}
    long next();

private:
    short counter_;
    static short prefix_;
    static short const max_counter_ = 32767l;
};

// Switch to random-number as initial prefix for production code.
// short generate_id::prefix_(static_cast<short>(std::rand())));
short generate_id::prefix_{1};;
short const generate_id::max_counter_;

long generate_id::next() {
    if (counter_ == max_counter_) {
        counter_ = 0;
    } else {
        ++counter_;
    }
    return static_cast<long>(prefix_) * (max_counter_ + 1) + counter_;
}

int main() {
    generate_id gen;            // Create ID generator
    for (int i{0}; i != 10; ++i) {
        std::cout << gen.next() << "\n";
    }
}