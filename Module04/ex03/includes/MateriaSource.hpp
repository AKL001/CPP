#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define SLOTS 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materias[SLOTS];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& cp);
        MateriaSource& operator=(const MateriaSource& cp);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif