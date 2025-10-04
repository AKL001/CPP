/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:51:19 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 10:51:20 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : _name(name) , _weapon(NULL)
{
    
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
    if (_weapon)
        std::cout << _name << ": attacks with their " << _weapon->getType() << std::endl;
    else 
        std::cout << _name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}