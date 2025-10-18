#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(const Animal& cp) : type(cp.type)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal&  Animal::operator=(const Animal& cp)
{
    std::cout << "Animal Copy Assignment Constructor Called" << std::endl;
    if (this != &cp)
        type = cp.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

void Animal::makeSound()
{
    std::cout << "Animal make no sound" << std::endl;
}