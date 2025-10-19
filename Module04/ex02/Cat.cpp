#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& cp) : AAnimal(cp)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    // delete _brain;
    _brain = new Brain(*cp._brain);  
}

Cat& Cat::operator=(const Cat& cp)
{
    std::cout << "Cat Copy Assignment Called" << std::endl;
    if (this != &cp)
    {
        AAnimal::operator=(cp);
        *_brain = *cp._brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
    delete _brain;
}

void Cat::makeSound()
{
    std::cout << "Meow Meow" << std::endl;
}

const std::string& Cat::getType(void) const
{
    return type;
}

Brain* Cat::getBrain() const
{
    return _brain;
}