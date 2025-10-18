#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& cp) : Animal(cp)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& cp)
{
    std::cout << "Cat Copy Assignment Called" << std::endl;
    if (this != &cp)
        Animal::operator=(cp);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Meow Meow" << std::endl;
}

const std::string& Cat::getType(void) const
{
    return type;
}