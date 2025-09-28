#include "Zombie.hpp"
#include <iostream>


int main(int ac,char **av)
{
    
    if (ac != 2)
    {
        std::cout << "./Zombie <name>" << std::endl;
        return 1;
    }
    if (av[1])
    {
        Zombie *zombie = newZombie(av[1]);
        zombie->announce();
        std::cout << "random" << std::endl;
        randomChump(av[1]);
        
        delete zombie;
        // destroctore will be called to destroy the class
        return 0;
    }

}