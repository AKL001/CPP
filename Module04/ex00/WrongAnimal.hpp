#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& cp);
        WrongAnimal& operator=(const WrongAnimal& cp);
        void makeSound();
        const std::string& getType(void) const;
        virtual ~WrongAnimal();
};

#endif