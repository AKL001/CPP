#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        const std::string type;
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& cp);
        AMateria& operator=(const AMateria& cp);
        std::string const & getType() const; //Returns the materia type
        virtual ~AMateria();
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    
};


#endif