#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("UNKOWN") , _hitPoints(10) , _energyPoints(10) , _attackDmg(10)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name) , _hitPoints(10) , _energyPoints(10) , _attackDmg(10)
{
    std::cout << "ClapTrap " << _name << " is alive and ready to Fight!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hp,unsigned int ep,unsigned int ad) : _name(name) , _hitPoints(hp) , _energyPoints(ep) , _attackDmg(ad) {}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called"<< std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &cp)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = cp;
}
// copy assignment constructor
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    // left hand 
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;                                                                                                      
        _energyPoints = other._energyPoints;
        _attackDmg = other._attackDmg;
    }
    return *this;
}

/* getters && setters*/

void ClapTrap::setName(const std::string &name)
{
    _name = name;
}

void ClapTrap::setHitPoints(int htp)
{
    _hitPoints = htp;
}

void ClapTrap::setEnergyPoints(int enp)
{
    _energyPoints = enp;
}

void ClapTrap::setAttackDmg(int ad)
{
    _attackDmg = ad;
}


const std::string &ClapTrap::getName(void) const
{
    return _name;
}

int ClapTrap::getHitPoints(void) const
{
    return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return _energyPoints;
}

int ClapTrap::getAttackDmg(void) const
{
    return _attackDmg;
}

// Claptrap cant do anything if hitpoints = 0 or energy = 0;
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        // ClapTrap <name> attacks <target>, causing <damage> points of damage!
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
    }
    else
       std::cout << "ClapTrap " << _name << " has no hit or energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
    else
    {
        if (amount >= _hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;

        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    // cost energy 
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        // ClapTrap <name> attacks <target>, causing <damage> points of damage!
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << ", hit points back ! " << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " No hit or energy points Left to repair !!!" << std::endl;

}