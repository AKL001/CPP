#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// std::string getDiamondName() const { return name; }
// std::string getClapName() const { return _name; }
// unsigned int getHitPoints() const { return _hitPoints; }
// unsigned int getEnergyPoints() const { return _energyPoints; }
// unsigned int getAttackDmg() const { return _attackDmg; }

class DiamondTrap : public FragTrap , public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap& cp);
        DiamondTrap& operator=(const DiamondTrap& cp);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();

};


#endif