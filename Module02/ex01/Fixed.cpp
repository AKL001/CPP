#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const int cnv)
{
    std::cout << "Int constructor called" << '\n';
    _fixedPoint = cnv << _fractionalBits;
}

Fixed::Fixed(const float cnv)
{
    std::cout << "Float constructor called" << '\n';
    // (1 << _fraction) same as cnv * 256 
    _fixedPoint = roundf(cnv * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << '\n';
}
// f = g;
Fixed::Fixed(const Fixed& cp)
{
    std::cout << "Copy constructor called" << '\n';
    *this = cp;
}


/*---------setters and getters---------*/
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << '\n';
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}
/*---------setters and getters---------*/


Fixed& Fixed::operator=(const Fixed& cp)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &cp)
        _fixedPoint = cp._fixedPoint;
    return *this;
}

/*----------Orthodox Canonical class form------------*/

/* member funtions*/
float Fixed::toFloat(void) const
{
    // (1 << _fraction) same as  256.0 
    return (float)_fixedPoint / (1 << _fractionalBits);
}

int   Fixed::toInt(void) const
{
    return (_fixedPoint >> _fractionalBits);
}

std::ostream& operator<<(std::ostream & out,const Fixed& cnv)
{
    out << cnv.toFloat();
    return out;
}