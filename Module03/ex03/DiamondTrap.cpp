#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// class DiamondTrap : public FragTrap , public ScavTrap
DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name) ,ScavTrap(name) , name(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDmg = 30;
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& cp) : ClapTrap(cp)
{
    this->name = cp.name;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap&cp)
{
    std::cout << "DiamondTrap Copy Assignment operator called" << std::endl;
    if (this != &cp)
    {
        ClapTrap::operator=(cp);
        name = cp.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called"<< std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    std::cout << "DiamondTrap " << name << " Using ScavTrap!" << std::endl;
    ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(void)
{
    std::cout << "Diamond name :" << name << std::endl;
    std::cout << "ClapTrap name :" << ClapTrap::_name << std::endl;
}