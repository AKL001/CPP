#include "includes/AMateria.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"
#include "includes/MateriaSource.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        Character* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        for (int i = 0; i < 10; i++)
            me->equip(src->createMateria("ice"));
        
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    Character::cleanFloor();
    return 0;
}


// #define RED     "\033[31m"
// #define GREEN   "\033[32m"
// #define BLUE    "\033[34m"
// #define YELLOW  "\033[33m"
// #define RESET   "\033[0m"

// int main()
// {
//     std::cout << BLUE << "=== Creating Characters ===" << RESET << std::endl;
//     Character* alice = new Character("Alice");
//     Character* bob = new Character("Bob");

//     std::cout << GREEN << "\n=== Creating Materia ===" << RESET << std::endl;
//     AMateria* ice = new Ice();
//     AMateria* cure = new Cure();

//     std::cout << YELLOW << "\n=== Equipping Alice ===" << RESET << std::endl;
//     alice->equip(ice);
//     alice->equip(cure);

//     std::cout << BLUE << "\n=== Using Materia ===" << RESET << std::endl;
//     alice->use(0, *bob); // ice
//     alice->use(1, *bob); // cure

//     std::cout << GREEN << "\n=== Deep Copy Test ===" << RESET << std::endl;
//     Character* copyAlice = new Character(*alice); // copy constructor
//     copyAlice->use(0, *bob);
//     copyAlice->use(1, *bob);

//     std::cout << YELLOW << "\n=== Unequip & Equip Tests ===" << RESET << std::endl;
//     alice->unequip(0);        // unequip ice
//     AMateria* newIce = new Ice();
//     alice->equip(newIce);     // equip new ice
//     alice->use(0, *bob);

//     std::cout << BLUE << "\n=== Assignment Operator Test ===" << RESET << std::endl;
//     Character assignChar("Temp");
//     assignChar = *alice;
//     assignChar.use(0, *bob);
//     assignChar.use(1, *bob);

//     // Clean up
//     delete alice;
//     delete bob;
//     delete copyAlice;
//     Character::cleanFloor();
//     return 0;
// }
