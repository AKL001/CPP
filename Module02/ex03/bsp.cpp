#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
               (b.getY() - a.getY()) * (point.getX() - a.getX());

    Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
               (c.getY() - b.getY()) * (point.getX() - b.getX());

    Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
               (a.getY() - c.getY()) * (point.getX() - c.getX());

    // convert to float for stable comparisons
    float fd1 = d1.toFloat();
    float fd2 = d2.toFloat();
    float fd3 = d3.toFloat();

    bool has_neg = (fd1 < 0) || (fd2 < 0) || (fd3 < 0); 
    bool has_pos = (fd1 > 0) || (fd2 > 0) || (fd3 > 0);
    bool has_zero = (fd1 == 0) || (fd2 == 0) || (fd3 == 0);
    if (has_zero)
        return false;
    return !(has_neg && has_pos);
}


