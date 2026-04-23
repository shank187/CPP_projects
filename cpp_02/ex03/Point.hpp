#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point& other);
    ~Point();

    Point& operator=(const Point& other);

    Fixed getX() const;
    Fixed getY() const;

private:
    const Fixed x;
    const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP