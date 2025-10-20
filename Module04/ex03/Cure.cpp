#include "includes/Cure.hpp"
#include "includes/AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &cp) : AMateria(cp)
{
}

Cure& Cure::operator=(const Cure& cp)
{
    if (this != &cp)
        AMateria::operator=(cp);
    return *this;
}

Cure::~Cure()
{
}

std::string const & Cure::getType() const
{
    return this->type;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

// void Cure::use(Icharacter& target)
// {
//     std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
// }
