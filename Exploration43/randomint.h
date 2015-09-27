//
// Created by carmen on 26/09/2015.
//

#ifndef EXPLORING_CPP_2E_RANDOMINT_H
#define EXPLORING_CPP_2E_RANDOMINT_H

#include <algorithm>
#include <random>

/// Generate uniformly distributed random integers in a range
class randomint {
public:
    typedef std::default_random_engine::result_type result_type;

    /// Construct a random-number generator to produce numbers in the range [<tt>low</tt>, <tt>high</tt>].
    /// if @p low > @p high the values are reversed
    randomint(result_type low, result_type high)
        // std::random_device uses a system-dependant generation of randomness
        // to send the pseudo-random-number generator.
        : prng_{std::random_device{}()} {}

    /// Generate the next random number generator.
    result_type operator()() {
        return distribution_(prng_);
    }

private:
    // implementation-defined pseudo-random-number generator
    std::default_random_engine prng_;

    // Map random numbers to a uniform distribution
    std::uniform_int_distribution<result_type> distribution_;
};
#endif //EXPLORING_CPP_2E_RANDOMINT_H
