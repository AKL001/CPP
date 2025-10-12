#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    // std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const int cnv)
{
    // std::cout << "Int constructor called" << '\n';
    _fixedPoint = cnv << _fractionalBits;
}

Fixed::Fixed(const float cnv)
{
    // std::cout << "Float constructor called" << '\n';
    // (1 << _fraction) same as cnv * 256 
    _fixedPoint = roundf(cnv * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << '\n';
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

// copy constructor
Fixed::Fixed(const Fixed& cp)
{
    // std::cout << "Copy constructor called" << '\n';
    *this = cp;
}

float Fixed::toFloat(void) const
{
    // (1 << _fraction) same as  256.0 
    return (float)_fixedPoint / (1 << _fractionalBits);
}

int   Fixed::toInt(void) const
{
    return (_fixedPoint >> _fractionalBits);
}

/*-------operatrs over load----------*/
Fixed& Fixed::operator=(const Fixed& cp)
{
    // std::cout << "Copy assignment operator called" << '\n';
    if (this != &cp)
        _fixedPoint = cp._fixedPoint;
    return *this;
}
/*------comparison operators---------*/

bool Fixed::operator>(const Fixed& other) const
{
    return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _fixedPoint != other._fixedPoint;
}

/*--------aithmetic operators--------*/

Fixed Fixed::operator+(const Fixed& rhp) const
{
    // We create and return a temporary Fixed object holding the sum.
    // Returning by value allows the caller to receive a new Fixed object.
    // Later, this temporary can be used to initialize a new object (copy constructor)
    // or be assigned to an existing object (copy assignment operator).
    Fixed result;
    result.setRawBits(this->_fixedPoint + rhp._fixedPoint);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhp) const
{
    Fixed result;
    result.setRawBits(this->_fixedPoint - rhp._fixedPoint);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhp) const
{
    Fixed result;
    result.setRawBits((this->_fixedPoint * rhp._fixedPoint) >> _fractionalBits);
    return Fixed(result);
}

Fixed Fixed::operator/(const Fixed& rhp) const
{
    Fixed result;
    result.setRawBits((this->_fixedPoint << _fractionalBits)  / rhp._fixedPoint);
    return result;
}

/*------Pre-increment && Post-increment------*/
Fixed& Fixed::operator++()
{
    // Prefix increment: increment the object first
    // We return a reference to the modified object (*this)
    // so that the caller gets the incremented value without creating a copy
    ++_fixedPoint;
    return *this;
}

Fixed Fixed::operator++(int)
{
    // Postfix increment: the 'int' parameter distinguishes this from prefix
    // Create a temporary copy of the current object to return the original value
    Fixed tmp(*this);
    // Increment the actual object
    ++_fixedPoint;
    // Return the copy representing the value before increment
    return tmp;
}

/*------Pre-decrement && Post-decrement------*/

Fixed& Fixed::operator--()
{
    --_fixedPoint;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_fixedPoint;
    return tmp;
}

/*------static overloaded -----*/

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b)? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b)? a : b;
}

std::ostream& operator<<(std::ostream & out,const Fixed& cnv)
{
    out << cnv.toFloat();
    return out;
}