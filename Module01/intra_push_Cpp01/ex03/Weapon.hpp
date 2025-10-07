/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:01 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:02 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon 
{
    private:
        std::string type;
        
    public:
        Weapon(std::string _type);
        ~Weapon();
        std::string const &getType(void) const;
        void setType(std::string type);
};

#endif
