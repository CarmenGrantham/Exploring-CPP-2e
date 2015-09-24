//
// Created by carmen on 24/09/2015.
//
#include "generate_id2.hpp"

// Switch to random-number as initial prefix for production code.
// short generate_id::prefix_(static_cast<short>(std::rand())));
short generate_id2::prefix_{1};;
short const generate_id2::max_counter_;

long generate_id2::next() {
    if (counter_ == max_counter_) {
        counter_ = 0;
    } else {
        ++counter_;
    }
    return static_cast<long>(prefix_) * (max_counter_ + 1) + counter_;
}

