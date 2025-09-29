#include "Zombie.hpp"
#include <iostream>


int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "./Zombie <name>" << std::endl;
        return 1;
    }
    // case if  av[1] = "            " , isspace ??
    if (!std::string(av[1]).empty())
    {
        std::cout << "Using Heap :" << std::endl;
        Zombie *zombie = newZombie(av[1]);
        zombie->announce();
        delete zombie;

        std::cout << "Stack :" << std::endl;
        
        randomChump(av[1]);
        return 0;
    }
    else
    {
        std::cout << "./Zombie <name>" << std::endl;
        return 1;
    }
}
