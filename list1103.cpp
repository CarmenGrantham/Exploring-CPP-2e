//
// Created by carmen on 11/08/2015.
//


#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data {};

    // Read integers one at a time from user input
    std::copy (std::istream_iterator<int>(std::cin),
               std::istream_iterator<int>(),
               std::back_inserter(data));

    // reverse the order of the vector
    for (std::vector<int>::iterator start{data.begin()}, end{data.end()}; start != end; /* empty */) {
        --end;
        if (start != end) {
            std::iter_swap(start, end);
            ++start;
        }
    }


    // print out the result
    std::copy(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, "\n" ));
}
