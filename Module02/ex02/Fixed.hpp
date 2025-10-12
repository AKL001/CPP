/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:17:26 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/12 11:55:32 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPoint; // store the fixed point number value
        static const int _fractionaBits = 8; // 
    public:
        // defalt constructor
        Fixed();
       // constructor  for int converting it to the fixed-point value
        Fixed(const int cnv);
        // constructor for float 
        Fixed(const float cnv);
        // Destructor called
        ~Fixed();
        /* copy constructor && copy assignment */
        Fixed(const Fixed& cp);
        Fixed& operator=(const Fixed& cp);

        /*-----comparison members------*/
        bool operator>(const Fixed& other) const; // const at the end means we dont change (*this) in the member function
        bool operator<(const Fixed& other)  const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        
        
};

    
#endif