/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:27:26 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/12 20:53:16 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP
#include <iostream>

class Fixed
{
    private:
        int _fixedPoint; // store the fixed point number value
        static const int _fractionalBits = 8; // 
    public:
        // constructor
        Fixed();
        // copy constructor 
        Fixed(const Fixed& cp);
        // copy assignment 
        Fixed&  operator=(const Fixed& cp);
        // destructor.
        ~Fixed();
        // getters & setters 
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif