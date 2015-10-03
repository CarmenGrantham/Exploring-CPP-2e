//
// Created by carmen on 3/10/2015.
//

#ifndef EXPLORING_CPP_2E_ERASE_LESS_H
#define EXPLORING_CPP_2E_ERASE_LESS_H
template<class Container>
void erase_less(Container& cont) {
    typename Container::iterator prev{cont.end()};
    typename Container::iterator iter{cont.begin()};

    while(iter != cont.end()) {
        if (prev != cont.end() and not (*prev < *iter)) {
            iter = cont.erase(iter);
        } else {
            prev = iter;
            ++iter;
        }
    }
}
#endif //EXPLORING_CPP_2E_ERASE_LESS_H
