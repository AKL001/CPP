/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:51:30 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 10:51:31 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{

}

Weapon::~Weapon()
{

}

std::string const &Weapon::getType(void) const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}