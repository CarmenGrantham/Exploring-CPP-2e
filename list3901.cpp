//
// Created by carmen on 23/09/2015.
//
#include <iostream>

typedef int height;
typedef int weight;
typedef int bmi;

bmi compute_bmi(height h, weight w) {
    return w * 10000 / (h * h);
}

int main() {
    std::cout << "Height in cms: ";
    height h{};
    std::cin >> h;

    std::cout << "Weight in kgs: ";
    weight w{};
    std::cin >> w;

    std::cout << "Body mass index= " << compute_bmi(w, h) << "\n";      // Ooops, weight and height are in the wrong order
}
