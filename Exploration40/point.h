//
// Created by carmen on 24/09/2015.
//

#ifndef EXPLORING_CPP_2E_POINT_H
#define EXPLORING_CPP_2E_POINT_H

class point {
public:
    point() : point { 0, 0} {}
    point(int x, int y) : x_{x}, y_{y} {}
    int x() const { return x_; }
    int y() const { return y_; }

private:
    int y_, x_;
};
#endif //EXPLORING_CPP_2E_POINT_H
