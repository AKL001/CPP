#ifndef POINT_HPP
#define  POINT_HPP
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point(); // default constru that initislize x , y to zero
        Point(float const a,float const b); // init x , y ; with a and b
        Point(const Point &cp);
        Point& operator=(const Point &cp);
        ~Point();

        const Fixed &getX(void) const;
        const Fixed &getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

/*
Area=(x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)) / 2​
*/
#endif