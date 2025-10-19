#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const Cat& cp);
        Cat& operator=(const Cat& cp);
        ~Cat();
        void makeSound();
        const std::string& getType(void) const;
        Brain* getBrain() const;
};

#endif