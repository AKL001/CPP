#include "FragTrap.hpp"
#include "ClapTrap.hpp"


FragTrap::FragTrap() : ClapTrap() 
{
    std::cout << "FragTrap Default constructor called" << std::endl;
};

FragTrap::FragTrap(const std::string &name) : ClapTrap(name,100,100,30)
{
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cp) : ClapTrap(cp)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &cp)
{
    std::cout << "ScavTrap Copy Assignment Called" << std::endl;
    if (this != &cp)
        ClapTrap::operator=(cp);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called"<< std::endl;
}

void FragTrap::highFivesGuys(void) {
        std::cout << "FragTrap " << _name << " is requesting a high five! ✋" << std::endl;
}
