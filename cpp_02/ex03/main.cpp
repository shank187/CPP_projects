#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include "Point.hpp"

// Forward declaration (if not in a header)
bool bsp(Point const a, Point const b, Point const c, Point const point);

void test_case(const Point& a, const Point& b, const Point& c, const Point& p, const std::string& label)
{
    std::cout << "=== " << label << " ===" << std::endl;
    std::cout << "Triangle: A(" << a.getX() << ", " << a.getY()
              << "), B(" << b.getX() << ", " << b.getY()
              << "), C(" << c.getX() << ", " << c.getY() << ")\n";
    std::cout << "Point: P(" << p.getX() << ", " << p.getY() << ")\n";

    bool inside = bsp(a, b, c, p);
    std::cout << "Result: P is " 
              << (inside ? "INSIDE ✅" : "OUTSIDE ❌") 
              << " the triangle\n\n";
}

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // ✅ Inside
    Point p1(5, 3);
    test_case(a, b, c, p1, "Case 1: Inside");

    // ❌ Outside (below the base)
    Point p2(5, -1);
    test_case(a, b, c, p2, "Case 2: Below");

    // ❌ Outside (to the right)
    Point p3(11, 3);
    test_case(a, b, c, p3, "Case 3: Outside right");

    // ⚠️ On the edge AB
    Point p4(5, 0);
    test_case(a, b, c, p4, "Case 4: On edge AB");

    // ⚠️ On the vertex A
    Point p5(0, 0);
    test_case(a, b, c, p5, "Case 5: On vertex A");

    // ✅ Inside near center
    Point p6(5, 4.9f);
    test_case(a, b, c, p6, "Case 6: Deep inside");

    // ❌ Clearly outside far away
    Point p7(20, 20);
    test_case(a, b, c, p7, "Case 7: Far outside");

    // ✅ Another inside near edge
    Point p8(4, 2);
    test_case(a, b, c, p8, "Case 8: Inside near edge");

    // ✅ Small triangle test
    Point a2(0, 0), b2(2, 0), c2(1, 2);
    Point p9(1, 0.5f);
    test_case(a2, b2, c2, p9, "Case 9: Small triangle inside");

    // ❌ Small triangle outside
    Point p10(3, 3);
    test_case(a2, b2, c2, p10, "Case 10: Small triangle outside");

    return 0;
}
