#include "includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& cp) : type(cp.type)
{
}

AMateria& AMateria::operator=(const AMateria& cp)
{
    (void)cp;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return this->type;
}
