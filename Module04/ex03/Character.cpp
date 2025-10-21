#include "includes/Character.hpp"
#include "includes/AMateria.hpp"
#include "includes/ICharacter.hpp"

AMateria *floor[MAX_FLOOR];
int floor_count = 0;

Character::Character() : _name("UKNOWN_Character")
{
    for (int i=0;i < SLOTS; i++)
        _inverntory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    for (int i=0;i < SLOTS; i++)
        _inverntory[i] = NULL;
}

Character::Character(const Character &cp)
{
    *this = cp;
}


Character& Character::operator=(const Character& cp)
{
    if (this != &cp)
    {
        _name = cp._name;
        for (int i = 0; i < SLOTS; i++)
        {
            if (_inverntory[i] != NULL)
            {
                delete _inverntory[i];
                _inverntory[i] = NULL;
            }

            if (cp._inverntory[i] != NULL)
                _inverntory[i] = cp._inverntory[i]->clone();
            else
                _inverntory[i] = NULL;
        }
    }
    return *this;
}


Character::~Character()
{
    for (int i = 0; i < SLOTS; i++)
    {
        if (_inverntory[i] != NULL)
        {
            delete _inverntory[i];
            _inverntory[i] = NULL;
        }
    }
    
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < SLOTS ;i++)
    {
        if (_inverntory[i] == NULL)
        {
            _inverntory[i] = m;
            return;
        }
    }
    // if the inventory is full we add the equipe to the floor 
    if (floor_count < MAX_FLOOR)
        floor[floor_count++] = m;
    else
        delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (_inverntory[idx])
        floor[floor_count++] = _inverntory[idx];
    _inverntory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= SLOTS || !_inverntory[idx])
        return;
    _inverntory[idx]->use(target);
}

void Character::cleanFloor()
{
    for (int i = 0; i < floor_count; i++)
    {
        if (floor[i])
        {
            delete floor[i];
            floor[i] = NULL;
        }
    }
    floor_count = 0;
}

void Character::debugFloor()
{
    std::cout << "Floor count = " << floor_count << std::endl;
    for (int i = 0; i < floor_count; i++)
    {
        if (floor[i])
            std::cout << "Floor[" << i << "] exists" << std::endl;
        else
            std::cout << "Floor[" << i << "] is NULL" << std::endl;
    }
}
