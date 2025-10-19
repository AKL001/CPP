#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog& cp);
        Dog& operator=(const Dog& cp);
        ~Dog();
        void makeSound();
        const std::string& getType(void) const;
        Brain* getBrain() const;
};

#endif