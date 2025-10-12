#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const int cnv)
{
    std::cout << "Int constructor called" << '\n';
    _fixedPoint = cnv << _fractionaBits;
}

Fixed::Fixed(const float cnv)
{
    std::cout << "Float constructor called" << '\n';
    // (1 << _fraction) same as cnv * 256 
    _fixedPoint = roundf(cnv * (1 << _fractionaBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << '\n';
}

Fixed::Fixed(const Fixed& cp)
{
    std::cout << "Copy constructor called" << '\n';
    *this = cp;
}


/*-------operatrs over load----------*/
Fixed& Fixed::operator=(const Fixed& cp)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &cp)
        _fixedPoint = cp._fixedPoint;
    return *this;
}
/*------comparison operators---------*/

bool Fixed::operator>(const Fixed& other) const
{
    return this->_fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_fixedPoint < other._fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->_fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->_fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_fixedPoint != other._fixedPoint;
}

/*--------aithmetic operators--------*/




