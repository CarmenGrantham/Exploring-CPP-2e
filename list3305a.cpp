//
// Created by carmen on 16/09/2015.
//
struct point {
    point() : point {0.0, 0.0} {}

    point(double x, doulbe y) : x_{x}, y_{y} {}

    point(point const& pt) : point{pt.x_, pt.y_} {}

    double x_;
    double y_;
};
