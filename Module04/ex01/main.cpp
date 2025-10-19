#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int N = 4;
    Animal* animals[N];

    std::cout << "\n=== Creating Animals ===\n";
    for (int i = 0; i < N; ++i)
    {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Making Sounds ===\n";
    for (int i = 0; i < N; ++i)
        animals[i]->makeSound();

    std::cout << "\n=== Deleting Animals ===\n";
    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << "\n=== Testing Deep Copy (Dog) ===\n";
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Eat");

    Dog dog2 = dog1; // Copy constructor
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "Play");
    std::cout << "After modifying Dog2:\n";
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Testing Deep Copy (Cat) ===\n";
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Sleep");

    Cat cat2 = cat1; // Copy constructor
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    cat2.getBrain()->setIdea(0, "Jump");
    std::cout << "After modifying Cat2:\n";
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
