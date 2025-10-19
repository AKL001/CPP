#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    AAnimal *rengo = new Cat();
    AAnimal *nasus = new Dog();


    std::cout << std::endl;
    rengo->makeSound();
    std::cout << std::endl;

    std::cout << std::endl;
    nasus->makeSound();
    std::cout << std::endl;


    delete rengo;delete nasus;
    return 0;
}
