#include "Fixed.hpp"
#include "Point.hpp"


Fixed get_triangle_area(Point p1, Point p2, Point p3)
{
    Point vector1(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    Point vector2(p1.getX() - p3.getX(), p1.getY() - p3.getY());

    Fixed cross_product = vector1.getX() * vector2.getY() - vector1.getY()* vector2.getX();
    if (cross_product < Fixed(0))
        cross_product = cross_product * Fixed(-1);
    return cross_product / Fixed(2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed triangle_area = get_triangle_area(a, b, c);
    Fixed sub_tri_1_area = get_triangle_area(point, a, b);
    Fixed sub_tri_2_area = get_triangle_area(point, b, c);
    Fixed sub_tri_3_area = get_triangle_area(point, c, a);

    return (
        (sub_tri_1_area > Fixed(0)) &&
        (sub_tri_2_area > Fixed(0)) &&
        (sub_tri_3_area > Fixed(0)) &&
        (triangle_area == sub_tri_1_area + sub_tri_2_area + sub_tri_3_area)
    );
}