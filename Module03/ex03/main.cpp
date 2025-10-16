#include "DiamondTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


// int main()
// {
//     std::cout << "=== DiamondTrap Test ===" << std::endl;
//     DiamondTrap dt("TestBot");

//     std::cout << "DiamondTrap name: " << dt.getDiamondName() << std::endl; // your private name
//     std::cout << "ClapTrap name: " << dt.getClapName() << std::endl;       // _name from ClapTrap
//     std::cout << "Hit Points: " << dt.getHitPoints() << std::endl;
//     std::cout << "Energy Points: " << dt.getEnergyPoints() << std::endl;
//     std::cout << "Attack Damage: " << dt.getAttackDmg() << std::endl;

//     return 0;
// }

int main()
{
    std::cout << CYAN << "=== Creating default DiamondTrap ===" << RESET << std::endl;
    DiamondTrap dt1("YASUO");

    std::cout << GREEN << "\n=== Testing attack() (ScavTrap version) ===" << RESET << std::endl;
    dt1.attack("DARIUS");

    std::cout << YELLOW << "\n=== Testing whoAmI() ===" << RESET << std::endl;
    dt1.whoAmI();

    std::cout << MAGENTA << "\n=== Testing copy constructor ===" << RESET << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();   
    dt2.attack("LEESIN");

    std::cout << BLUE << "\n=== Testing copy assignment ===" << RESET << std::endl;
    DiamondTrap dt3("BLITZ");
    dt3 = dt1;
    dt3.whoAmI();
    dt3.attack("ZIGGS");

    std::cout << RED << "\n=== End of main: destructors called ===" << RESET << std::endl;
    return 0;
}

