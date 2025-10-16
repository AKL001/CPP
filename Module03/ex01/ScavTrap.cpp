/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:05 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/16 12:52:39 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100 ,50,20)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cp) : ClapTrap(cp)
{
    // we only have private memebers in Scav , the only reason we need to copy
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    // we only have private memebers in Scav , the only reason we need to copy
    std::cout << "ScavTrap Copy Assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        // ClapTrap <name> attacks <target>, causing <damage> points of damage!
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
    }
    else
       std::cout << "ScavTrap " << _name << " has no hit or energy points left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< _name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called"<< std::endl;
}
