#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

int main()
{
    std::cout << CYAN << "\n=== Creating animals ===\n" << RESET;
    Animal* meta = new Animal();
    Animal* d = new Dog();
    Animal* c = new Cat();

    std::cout << CYAN << "\n=== Displaying types ===\n" << RESET;
    std::cout << GREEN << d->getType() << RESET << std::endl;
    std::cout << GREEN << c->getType() << RESET << std::endl;
    std::cout << GREEN << meta->getType() << RESET << std::endl;

    std::cout << CYAN << "\n=== Making sounds ===\n" << RESET;
    d->makeSound();
    c->makeSound();
    meta->makeSound();

    std::cout << CYAN << "\n=== Copy constructor tests ===\n" << RESET;
    /* 
        Dynamic_cast vs static_cast
        -Dynamic_cast checked at run time , works only  for polymorphic types 
            meaning base class have at least one virtual function,
            RETURN : null at run time ,
        -Static_cast : when you know the exact derived type at compile time. 
    */
    Dog* d_copy = new Dog(*static_cast<Dog*>(d));
    Cat* c_copy = new Cat(*static_cast<Cat*>(c));
    
    std::cout << GREEN << d_copy->getType() << RESET << std::endl;
    d_copy->makeSound();
    std::cout << GREEN << c_copy->getType() << RESET << std::endl;
    c_copy->makeSound();

    std::cout << CYAN << "\n=== Assignment operator tests ===\n" << RESET;
    *d_copy = *static_cast<Dog*>(d);
    *c_copy = *static_cast<Cat*>(c);

    std::cout << CYAN << "\n=== Deleting animals ===\n" << RESET;
    delete meta;
    delete d;
    delete c;
    delete d_copy;
    delete c_copy;
    std::cout << MAGENTA << "\n=== Wrong Test ===\n" << RESET;

    WrongAnimal *wrong_cat = new WrongCat();
    WrongAnimal *wrong_animal = new WrongAnimal();
    
    wrong_animal->makeSound();
    wrong_cat->makeSound();

    delete wrong_animal;delete wrong_cat;
    std::cout << MAGENTA << "\n=== Test complete ===\n" << RESET;
    return 0;
}
