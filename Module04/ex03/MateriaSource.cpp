#include "includes/MateriaSource.hpp"
#include "includes/AMateria.hpp"


MateriaSource::MateriaSource()
{
    for(int i=0 ; i < SLOTS ;i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& cp)
{
    *this = cp;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& cp)
{
    if (this != &cp)
    {
        for (int i = 0; i < SLOTS;i++)
        {
            if (_materias[i] != NULL)
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
            if (cp._materias[i] != NULL)
                _materias[i] = cp._materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i =0; i < SLOTS;i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* learn)
{
    if (!learn)
        return;
    for (int i = 0; i < SLOTS ; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = learn->clone();
            delete learn;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < SLOTS; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
