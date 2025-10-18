#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& cp);
        Animal& operator=(const Animal& cp);
        ~Animal();
        void makeSound();
};

#endif