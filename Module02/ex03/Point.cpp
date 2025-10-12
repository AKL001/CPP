#include "Point.hpp"
#include "Fixed.hpp"

/*--------Oethodox canonical class form----------*/
Point::Point(): _x(0) , _y(0)
{
}

Point::~Point()
{
}

Point::Point(float const a,float const b) : _x(a) , _y(b)
{
} 
Point::Point(const Point &cp)
{
    *this = cp;
}

Point& Point::operator=(const Point &cp)
{
    // the copy assignment is not use cuz we have const Fixed values cant be changed
    // only the constructor that can initialize them
    (void)cp;
    return *this;
}

/*------setters && getters------*/

Fixed Point::getX(void) const
{
    return this->_x;
}  

Fixed Point::getY(void) const
{
    return this->_y;
}