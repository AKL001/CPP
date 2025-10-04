/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:53:00 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 10:53:01 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <ostream>

// constructor
Zombie::Zombie(std::string name) {
    this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie: " << _name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
  Zombie  zombie(name);
  zombie.announce();
}