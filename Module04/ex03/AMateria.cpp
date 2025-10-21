#include "includes/AMateria.hpp"
#include "includes/Character.hpp"

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

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}