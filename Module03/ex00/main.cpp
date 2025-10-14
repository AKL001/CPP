#include "ClapTrap.hpp"

// Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main(void)
{
    ClapTrap yasuo("Yasuo");
    ClapTrap darius("Darius");

    std::cout << BLUE << "\n=== Battle Start ===\n" << RESET;

    std::cout << CYAN;
    yasuo.attack("Darius");
    std::cout << RESET;

    std::cout << RED;
    darius.takeDamage(yasuo.getAttackDmg());
    std::cout << RESET;

    std::cout << RED;
    darius.attack("Yasuo");
    std::cout << RESET;

    std::cout << GREEN;
    darius.beRepaired(3);
    std::cout << RESET;

    std::cout << YELLOW << "\n=== Battle End ===\n" << RESET;

    return 0;
}
