//
// Created by carmen on 27/09/2015.
//
#include <algorithm>

#include "data.h"
#include "intrange.h"

int main() {
    intvector data {};
    read_data(data);
    write_data(data);

    std::replace_if(data.begin(), data.end(), [](int x) { return x >= 10 and x <= 20; }, 0);
    write_data(data);
}


