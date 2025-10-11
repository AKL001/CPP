/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:27:42 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/11 15:28:39 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
    _fixedPoint = 0;
    std::cout << "Default constructor called" << '\n';
}

// destructor.
Fixed::~Fixed()
{
    std::cout << "Destructor called" << '\n';
}

// copy constructor 
// f = g;
Fixed::Fixed(const Fixed& cp)
{
    std::cout << "Copy constructor called" << '\n';
    // left = right , we copy left to right g to f 
    // we over write f with g 
    *this = cp;
}

// copy assignment 
Fixed& Fixed::operator=(const Fixed& cp)
{
    std::cout << "Copy assignment operator called" << '\n';
    if(this != &cp) // we prevent from self assigning 
        _fixedPoint = cp.getRawBits();
    return *this;
}

// getters & setters 
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << '\n';
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}
