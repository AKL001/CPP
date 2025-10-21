#include "includes/Ice.hpp"
#include "includes/AMateria.hpp"
#include "includes/ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &cp) : AMateria(cp)
{
}

Ice& Ice::operator=(const Ice &cp)
{
    if (this != &cp)
        AMateria::operator=(cp);
    return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

std::string const& Ice::getType() const
{
    return this->type;
} 

void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}