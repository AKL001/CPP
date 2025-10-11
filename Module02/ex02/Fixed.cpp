#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << '\n';
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

Fixed& Fixed::operator=(const Fixed& cp)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &cp)
        _fixedPoint = cp._fixedPoint;
    return *this;
}