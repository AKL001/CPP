#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& cp) : type(cp.type)
{
    std::cout << "AAnimal Copy Constructor Called" << std::endl;
}

AAnimal&  AAnimal::operator=(const AAnimal& cp)
{
    std::cout << "AAnimal Copy Assignment Called" << std::endl;
    if (this != &cp)
        type = cp.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor" << std::endl;
}


const std::string& AAnimal::getType(void) const
{
    return this->type;
}