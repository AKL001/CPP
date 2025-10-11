/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:17:26 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/11 17:49:44 by ablabib          ###   ########.fr       */
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
        ~Fixed();
        /* copy constructor && copy assignment */
        Fixed(const Fixed& cp);
        Fixed& operator=(const Fixed& cp);

};

    
#endif