#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap& cp);
        FragTrap operator=(const FragTrap &cp);
        ~FragTrap();
        void highFivesGuys(void);
};



#endif