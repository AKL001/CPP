#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
    std::cout << CYAN << "=== Creating ClapTrap ===" << RESET << std::endl;
    ClapTrap c1("Clappy");
    std::cout << std::endl;

    std::cout << GREEN << "=== Creating ScavTrap ===" << RESET << std::endl;
    ScavTrap s1("Scavy");
    std::cout << std::endl;

    std::cout << YELLOW << "=== Testing attack ===" << RESET << std::endl;
    c1.attack("Target1");
    s1.attack("Target2");
    std::cout << std::endl;

    std::cout << MAGENTA << "=== Testing guardGate() ===" << RESET << std::endl;
    s1.guardGate();
    std::cout << std::endl;

    std::cout << RED << "=== Testing copy constructor ===" << RESET << std::endl;
    ScavTrap s2(s1); // copy constructor
    s2.guardGate();
    s2.attack("Target3");
    std::cout << std::endl;

    std::cout << BLUE << "=== Testing assignment operator ===" << RESET << std::endl;
    ScavTrap s3;
    s3 = s1;
    s3.attack("Target4");
    s3.guardGate();
    std::cout << std::endl;

    std::cout << CYAN << "=== End of main: destructors called ===" << RESET << std::endl;
    return 0;
}
