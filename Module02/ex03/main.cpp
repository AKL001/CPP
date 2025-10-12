#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    // Define triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test points
    Point inside1(5.0f, 5.0f);       // clearly inside
    Point inside2(6.0f, 4.0f);       // another inside
    Point outside1(10.0f, 10.0f);    // outside
    Point outside2(-1.0f, 5.0f);     // outside
    Point edge1(5.0f, 0.0f);         // on bottom edge
    Point edge2(7.5f, 5.0f);         // on right edge
    Point edge3(2.5f, 5.0f);         // on left edge
    Point vertex1(0.0f, 0.0f);       // vertex a
    Point vertex2(10.0f, 0.0f);      // vertex b
    Point vertex3(5.0f, 10.0f);      // vertex c


    std::cout << std::boolalpha;

    std::cout << "Inside1 (5,5): " << bsp(a, b, c, inside1) << std::endl;
    std::cout << "Inside2 (6,4): " << bsp(a, b, c, inside2) << std::endl;

    std::cout << "Outside1 (10,10): " << bsp(a, b, c, outside1) << std::endl;
    std::cout << "Outside2 (-1,5): " << bsp(a, b, c, outside2) << std::endl;

    std::cout << "Edge1 (5,0): " << bsp(a, b, c, edge1) << std::endl;
    std::cout << "Edge2 (7.5,5): " << bsp(a, b, c, edge2) << std::endl;
    std::cout << "Edge3 (2.5,5): " << bsp(a, b, c, edge3) << std::endl;

    std::cout << "Vertex1 (0,0): " << bsp(a, b, c, vertex1) << std::endl;
    std::cout << "Vertex2 (10,0): " << bsp(a, b, c, vertex2) << std::endl;
    std::cout << "Vertex3 (5,10): " << bsp(a, b, c, vertex3) << std::endl;

    return 0;
}
