#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& cp);
        Dog& operator=(const Dog& cp);
        ~Dog();
        void makeSound();
        const std::string& getType(void) const;
};

#endif