/** @file */
#include "utils.hpp"

Point::Point(long double x, long double y) : y(y), x(x) {}

Point::Point() : y(0), x(0) {}

bool Point::operator<(Point p2) {
    if (x != p2.x) {
        return x < p2.x;
    } else {
        return y < p2.y;
    }
    return false;
}