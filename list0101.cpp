//
// Created by carmen on 2/08/2015.
//
// Notes. In CLion I had to change the working directory in Run/Debug Configuration to the directory this file is in so
//        that it could find Program Argument list0101.txt

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


void read(std::istream& in, std::vector<std::string>& text) {
    std::string line;
    while (std::getline(in, line))
        text.push_back(line);

}

int main(int argc, char* argv[]) {

    std::cout << "Hello World!" << std::endl;

    // Part 1. Read the entire input into text. If the command line names a file,
    // read that file. Otherwise read the standard input.
    std::vector<std::string> text;	///< Store the lines of text here

    if (argc < 2) {
        read(std::cin, text);
    } else {
        std::ifstream in(argv[1]);
        if (not in) {
            std::perror(argv[1]);
            return EXIT_FAILURE;
        }
        read(in, text);
    }

    // Part 2. Sort the text.
    std::sort(text.begin(), text.end());

    // Part 3. Print the sorted text.
    std::copy(text.begin(), text.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}
