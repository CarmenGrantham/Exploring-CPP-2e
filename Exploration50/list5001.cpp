//
// Created by carmen on 29/09/2015.
//
#include <iostream>
#include <typeinfo>

template<class T>
class point {
public:
    typedef T value_type;
    point(T const& x, T const& y) : x_{x}, y_{y}{ std::cout << "point<" << typeid(T).name() << "> constructor\n"; }
    point() : point{T{}, T{}} {}
    T const& x() const { return x_; }
    T const& y() const { return y_; }

    void move_absolute(T const& x, T const y) {
        x_ = x;
        y_ = y;
    }

    void move_relative(T const& dx, T const& dy) {
        x_ += dx;
        y_ += dy;
    }

private:
    T x_;
    T y_;
};

template<>
class point<int> {
public:
    typedef int value_type;
    point(int x, int y) : x_{x}, y_{y}{ std::cout << "point<int> constructor\n";}
    point() : point{0, 0} {}
    int x() const { return x_; }
    int y() const { return y_; }

    void move_absolute(int x, int y) {
        x_ = x;
        y_ = y;
    }

    void move_relative(int dx, int dy) {
        x_ += dx;
        y_ += dy;
    }

private:
    int x_;
    int y_;
};

int main() {
    point<double> p1 {20.3, 4};
    point<int> p2 {100, 100};
    point<short> p3 {45, 30};
}