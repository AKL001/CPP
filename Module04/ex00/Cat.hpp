#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"


class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& cp);
        Cat& operator=(const Cat& cp);
        ~Cat();
        void makeSound();
        const std::string& getType(void) const;
};

#endif