//
// Created by carmen on 16/09/2015.
//

#include <cmath>

struct point {
    double distance() {
        return std::sqrt(x*x + y*y);
    }

    double angle() {
        return std::atan2(y, x);
    }

    void offset(double off) {
        offset(off, off);
    }

    void offset(double xoff, double yoff) {
        x = x + xoff;
        y = y + yoff;
    }

    void scale(double mult) {
        this->scale(mult, mult);
    }

    void scale(double xmult, double ymult) {
        this->x = this->x * xmult;
        this->y = this->y * ymult;
    }

    double x;
    double y;

};