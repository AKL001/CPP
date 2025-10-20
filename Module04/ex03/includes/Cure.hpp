#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &cp);
        Cure& operator=(const Cure& cp);
        ~Cure();
        std::string const & getType() const;
        AMateria* clone() const;
        // void use(Icharacter& target);


};

#endif