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