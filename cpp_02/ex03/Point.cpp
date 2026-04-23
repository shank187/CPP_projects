#include "Point.hpp"
#include "Fixed.hpp"


Point::Point() : x(0), y(0) {}
Point::Point(Fixed x, Fixed y) : x(x), y(y) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // Since x and y are const, we cannot assign to them.
        // This operator= is effectively useless in this case.
    }
    return *this;
}

Fixed Point::getX() const {
    return x;
}
Fixed Point::getY() const {
    return y;
}
