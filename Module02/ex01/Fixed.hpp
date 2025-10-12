/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:17:26 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/12 13:50:16 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP
#include <iostream>

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
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        /* copy constructor && copy assignment */
        Fixed(const Fixed& cp);
        Fixed& operator=(const Fixed& cp);
        
        /* member funtions*/
        float toFloat(void) const;
        int   toInt(void) const;
        
        /* manipulating the out stream */
        
};

std::ostream& operator<<(std::ostream & out,const Fixed& cnv);
    
#endif