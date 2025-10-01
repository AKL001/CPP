#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{

}

Weapon::~Weapon()
{

}

std::string const &Weapon::getType(void) const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}