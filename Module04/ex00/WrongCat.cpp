#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& cp) : WrongAnimal(cp)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cp)
{
    std::cout << "WrongCat Copy Assignment Called" << std::endl;
    if (this != &cp)
        WrongAnimal::operator=(cp);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << RED << "Meow Meow" << RESET << std::endl;
}

const std::string& WrongCat::getType(void) const
{
    return type;
}