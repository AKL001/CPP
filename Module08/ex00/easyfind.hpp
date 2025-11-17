#pragma  once 
#include <cstddef>
#include <exception>
#include <algorithm>
#include <iostream>

class NoOccurrenceIsFound : public std::exception
{
    public:
        const char * what() const throw();
};

template <typename T>
int easyfind(T& container,int a)  
{
    typename T::iterator it;
    it = std::find(container.begin(),container.end(),a);
    if (it != container.end())
        return *it;
    throw  NoOccurrenceIsFound();
}
