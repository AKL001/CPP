#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& cp) : Animal(cp)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& cp)
{
    std::cout << "Dog Copy Assignment Called" << std::endl;
    if (this != &cp)
        Animal::operator=(cp);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
}
void Dog::makeSound()
{
    std::cout << "Woof Woof" << std::endl;
}

const std::string& Dog::getType(void) const
{
    return this->type;
}