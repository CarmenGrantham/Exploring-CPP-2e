//
// Created by carmen on 24/09/2015.
//

#ifndef EXPLORING_CPP_2E_GENERATE_ID_H
#define EXPLORING_CPP_2E_GENERATE_ID_H

// Class for generating a unique ID number
class generate_id {
public:
    generate_id() : counter_{0} {}
    long operator()();

private:
    short counter_;
    static short prefix_;
    static short const max_counter_{32767l};
};

#endif //EXPLORING_CPP_2E_GENERATE_ID_H
