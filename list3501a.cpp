//
// Created by carmen on 19/09/2015.
//
#include <cmath>
#include <iostream>

struct point {

public:

    point() : point{0.0, 0.0}{};
    point(double x, double y) : x_{x}, y_{y}{};
    point(point const&) = default;

    double x() const {
        return x_;
    }
    double y() const {
        return y_;
    }

    double distance() const {
        return std::sqrt(x()*x() + y()*y());
    }

    double angle() const {
        return std::atan2(y(), x());
    }

    void move_cartesian(double x, double y) {
        x_ = x;
        y_ = y;
    }

    void move_polar(double r, double angle) {
        move_cartesian(r * std::cos(angle), r * std::sin(angle));
    }


    void offset(double off)  {
        offset(off, off);
    }

    void offset(double xoff, double yoff)  {
        move_cartesian(x() + xoff, y() +yoff);
    }

    void scale_cartesian(double s)  {
        scale_cartesian(s, s);
    }

    void scale_cartesian(double xs, double ys)  {
        move_cartesian(x() * xs, y() * ys);
    }

    void scale_polar(double r) {
        move_polar(distance() + r, angle());
    }
    void rotate(double a) {
        move_polar(distance(), angle() + a);
    }

private:
    double x_;
    double y_;

};

void print_polar(point const& pt) {
    std::cout << "{ r="<< pt.distance() << ", angle=" << pt.angle() << " }\n";
}

void print_cartesian(point const& pt) {
    std::cout << "{ x="<< pt.x()<< ", y=" << pt.y() << " }\n";
}

int main() {
    point p1{};
    point p2{};
    double const pi{3.141592653589792};
    p1.move_cartesian(std::cos(pi / 3), std::sin(pi / 3));
    print_polar(p1);
    print_cartesian(p1);

    p2 = p1;
    p2.scale_cartesian(4.0);
    print_polar(p2);
    print_cartesian(p2);

    p2.offset(0.0, -2.0);
    print_polar(p2);
    print_cartesian(p2);
}
