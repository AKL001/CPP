#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& cp)
{
    std::cout << "Brain Copy Constructor Calleds" << std::endl;
    *this = cp;
}

Brain& Brain::operator=(const Brain& cp)
{
    std::cout << "Brain Copy Assignment Called" << std::endl;
    if (this != &cp)
    {
        for (int i = 0; i < _IDEAS ; i++)
        {
            _ideas[i] = cp._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= _IDEAS)
        return "";
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index < 0 || index >= _IDEAS)
        return;
    _ideas[index] = idea;
}