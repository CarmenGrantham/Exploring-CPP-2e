//
// Created by carmen on 25/08/2015.
//


#include <iostream>
#include <string>

// Declaring functions so that main can be defined first
void ignore_line();
int prompted_red(std::string prompt);
void print_result(int count, int sum);


/** Main program
 * Read integers from the standard input and print statistics about them
 */
int main() {
    int sum{0};
    int count{0};

    while (std::cin) {
        int x{ prompted_red("Value: ")};
        if (std::cin) {
            sum = sum + x;
            ++count;
        }
    }
    print_result(count, sum);
}

/** Ignore the rest of the input line */
void ignore_line() {
    char c{};
    while (std::cin.get(c) and c != '\n') {
        /* empty */
    }
}

/** Prompt the user, then read a number and ignore the rest of the line
 * @param prompt the prompt string
 * @return the input number of 0 for end-of-file
 */
int prompted_red(std::string prompt) {
    std::cout << prompt;
    int x{0};
    std::cin >> x;
    ignore_line();
    return x;
}

/** Print the statistics
 * @param count the number of values
 * @param sum the sum of values
 */
void print_result(int count, int sum) {
    if (count == 0) {
        std::cout << "no data\n";
        return;
    }
    std::cout << "\ncount = " << count;
    std::cout << "\nsum   = " << sum;
    std::cout << "\nmean  = " << sum / count << "\n";
}
