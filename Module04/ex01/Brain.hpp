#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

#define IDEAS 100

class Brain
{
    private:
        std::string _ideas[IDEAS];
    public:
        Brain();
        Brain(const Brain& cp);
        Brain& operator=(const Brain& cp);
        ~Brain();
// Getters / Setters
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};


#endif