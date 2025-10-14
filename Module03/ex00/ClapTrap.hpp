#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{

    private:
        std::string _name;
        int         _hitPoints; // health of the claptrap 
        int         _energyPoints;
        int         _attackDmg;                                                                                                                                                                 
    
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &cp);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();                                            

        /* getter && setters*/
        void setName(const std::string &name);
        void setHitPoints(int htp);
        void setEnergyPoints(int enp);
        void setAttackDmg(int ad);

        const std::string &getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getAttackDmg(void) const;


        // Claptrap cant do anything if hitpoints = 0 or energy = 0;
        void attack(const std::string& target); // make the target lose hitpoints; (attack dmg) , when attack 1 energy is consumed
        void takeDamage(unsigned int amount);  // 
        void beRepaired(unsigned int amount);  // get <amount> self repair  get hitpoints back  , when repair 1 energy is lost 
        
}; 



#endif