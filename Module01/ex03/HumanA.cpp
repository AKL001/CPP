/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:51:10 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 10:51:11 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const &name , Weapon &weapon) : _name(name) , _weapon(weapon)
{
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::cout << _name << ": attacks with their " << _weapon.getType() << std::endl;
}
