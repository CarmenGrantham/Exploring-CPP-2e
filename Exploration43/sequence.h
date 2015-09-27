//
// Created by carmen on 24/09/2015.
//

#ifndef EXPLORING_CPP_2E_SEQUENCE_H
#define EXPLORING_CPP_2E_SEQUENCE_H

// Generate a sequence of integers
class sequence {
public:
    /// Construct the functor
    /// @param start the first value the generator returns
    /// @param step increment the value by this much for each call
    sequence(int start, int step) :value_{start}, step_{step} {}
    sequence(int start) : sequence{start, 1} {}
    sequence() : sequence{0} {}

    /// Return the current value in the sequence, and increment the value.
    int operator()() {
        int result(value_);
        value_ = value_ + step_;
        return result;
    }

private:
    int value_;
    int const step_;
};

#endif //EXPLORING_CPP_2E_SEQUENCE_H
