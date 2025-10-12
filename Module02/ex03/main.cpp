#include <iostream>
#include "Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    // Define triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test points
    Point inside(5.0f, 5.0f);
    Point outside(10.0f, 10.0f);
    Point edge1(5.0f, 0.0f);
    Point edge2(2.5f, 5.0f);
    Point vertex(0.0f, 0.0f);

    std::cout << std::boolalpha;

    std::cout << "Inside (5, 5): " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside (10, 10): " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Edge (5, 0): " << bsp(a, b, c, edge1) << std::endl;
    std::cout << "Edge (2.5, 5): " << bsp(a, b, c, edge2) << std::endl;
    std::cout << "Vertex (0, 0): " << bsp(a, b, c, vertex) << std::endl;

    return 0;
}
