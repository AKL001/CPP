#include "FragTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main(void)
{
    std::cout << BLUE << "=== Creating FragTrap with default constructor ===" << RESET << std::endl;
    FragTrap f1;
    std::cout << std::endl;

    std::cout << GREEN << "=== Creating FragTrap with name constructor ===" << RESET << std::endl;
    FragTrap f2("Fraggy");
    std::cout << std::endl;

    std::cout << YELLOW << "=== Testing highFivesGuys() ===" << RESET << std::endl;
    f1.highFivesGuys();
    f2.highFivesGuys();
    std::cout << std::endl;

    std::cout << RED << "=== Testing copy constructor ===" << RESET << std::endl;
    FragTrap f3(f2);
    f3.highFivesGuys();
    std::cout << std::endl;

    std::cout << CYAN << "=== Testing assignment operator ===" << RESET << std::endl;
    FragTrap f4;
    f4 = f2;
    f4.highFivesGuys();
    std::cout << std::endl;

    std::cout << MAGENTA << "=== End of main: destructors called ===" << RESET << std::endl;
    return 0;
}
