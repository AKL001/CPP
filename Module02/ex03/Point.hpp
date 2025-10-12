#ifndef POINT_HPP
#define  POINT_HPP
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(); // default constru that initislize x , y to zero
        Point(float const a,float const b); // init x , y ; with a and b
        Point(const Point &cp);
        Point& operator=(const Point &cp);
        ~Point();

        Fixed getX(void) const;
        Fixed getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

/*
Area=(x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)) / 2​
*/
#endif