#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp) : type(cp.type)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& cp)
{
    std::cout << "WrongAnimal Copy Assignment Called" << std::endl;
    if (this != &cp)
        type = cp.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound()
{
    std::cout <<  RED << "WrongAnimal make no sound" << RESET << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
    return this->type;
}