#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal& cp);
        AAnimal& operator=(const AAnimal& cp);
        virtual ~AAnimal();
        virtual void makeSound() = 0;
        virtual const std::string& getType(void) const;
};

#endif