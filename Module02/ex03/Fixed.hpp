/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:17:26 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/12 21:14:32 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP
#include <cmath>
#include <iostream>

class Fixed
{
    private:
        int _fixedPoint; // store the fixed point number value
        static const int _fractionalBits = 8; // 
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
        
        /* member funtions*/
        float toFloat(void) const;
        int   toInt(void) const;
        
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
        /*-----comparison arithmetic operators-----*/
        // "this" -> left-hand operand , other is the right-hand operand
        Fixed operator+(const Fixed& rhp) const;
        Fixed operator-(const Fixed& rhp) const;
        Fixed operator*(const Fixed& rhp) const;
        Fixed operator/(const Fixed& rhp) const;
        
        /*------Pre-increment && Post-increment------*/
        // Overloading the prefix operator
        Fixed& operator++();
        // Overloading the postfix operator | we need the dummy int for only postfix 
        Fixed operator++(int);
        /*------Pre-decrement && Post-decrement------*/
        Fixed& operator--();
        Fixed  operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);    
        
};

std::ostream& operator<<(std::ostream & out,const Fixed& cnv);

    
#endif