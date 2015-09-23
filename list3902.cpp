//
// Created by carmen on 23/09/2015.
//
#include <iostream>

class height {
public:
    height(int h) : value_{h} {}
    int value() const { return value_;}

private:
    int value_;
};

class weight {
public:
    weight(int w) : value_{w} {}
    int value() const { return value_;}

private:
    int value_;
};

class bmi {
public:
    bmi() : value_{0}{}
    bmi(height h, weight w) : value_{w.value() * 10000 / (h.value() * h.value())} {}
    int value() const { return value_; }

private:
    int value_;
};

height operator+(height a, height b) {
    return height{a.value() + b.value()};
}

int operator/(height a, height b) {
    return a.value() / b.value();
}

std::istream& operator>>(std::istream& in, height& h) {
    int tmp{};
    if (in >> tmp) {
        h = tmp;
    }
    return in;
}

std::istream& operator>>(std::istream& in, weight& w) {
    int tmp{};
    if (in >> tmp) {
        w = tmp;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, bmi i) {
    out << i.value();
    return out;
}

weight operator-(weight a, weight b) {
    return weight{a.value() - b.value()};
}

int main() {
    std::cout << "Height in cms: ";
    height h{0};
    std::cin >> h;

    std::cout << "Weight in kgs: ";
    weight w{0};
    std::cin >> w;

    std::cout << "Body mass index= " << bmi(h, w) << "\n";      // Now, in correct order, compiler complains if swapped
}
