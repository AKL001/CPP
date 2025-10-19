#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& cp) : Animal(cp)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = cp;
}   

Dog& Dog::operator=(const Dog& cp)
{
    std::cout << "Dog Copy Assignment Called" << std::endl;
    if (this != &cp)
    {
        Animal::operator=(cp);
        // over write the data
        *_brain = *cp._brain;
        // this would reallocate the data;
        // delete _brain;
        // _brain = new Brain(*cp._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
    delete _brain;
}
void Dog::makeSound()
{
    std::cout << "Woof Woof" << std::endl;
}

const std::string& Dog::getType(void) const
{
    return this->type;
}