//
// Created by carmen on 19/09/2015.
//
#include <cmath>
#include <iostream>

struct point {

public:

    point() : point{0.0, 0.0}{};
    point(double x, double y) : r_{0.0}, angle_{0.0} {
        move_cartesian(x, y);
    };
    point(point const&) = default;

    double x() const {
        return distance() * std::cos(angle());
    }
    double y() const {
        return distance() * std::sin(angle());
    }

    double distance() const {
        return r_;
    }

    double angle() const {
        return angle_;
    }

    void move_cartesian(double x, double y) {
        move_polar(std::sqrt(x*x + y*y), std::atan2(y, x));
    }

    void move_polar(double r, double angle) {
        r_ = r;
        angle_ = angle;
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
    double r_;
    double angle_;

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
