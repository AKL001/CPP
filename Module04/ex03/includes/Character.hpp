#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SLOTS 4
#define MAX_FLOOR 100

class Character : public ICharacter
{
    public:
        std::string _name;
        AMateria *_inverntory[SLOTS];
    public:
		Character();
		Character(std::string name);
		Character(const Character &cp);
		~Character();
		Character&			operator=(const Character& cp);
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
        static  void cleanFloor(void);
};

#endif