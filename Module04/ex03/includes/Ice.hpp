#ifndef ICE_HPP
#define  ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &cp);
        Ice& operator=(const Ice &cp);
        ~Ice(); 
        AMateria* clone() const;
        std::string const& getType() const;
        void use(ICharacter & target);

};

#endif