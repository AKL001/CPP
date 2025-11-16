#pragma  once 
#include <cstddef>
#include <exception>

class NoOccurrenceIsFound : public std::exception
{
    public:
        const char * what() const throw();
};

template <typename T>
size_t easyfind(T& x,int a)  
{
    typename T::iterator it;
    size_t i = 0;
    for (it = x.begin(); it != x.end();it++)
    {
        if (*it == a)
            return i;
        i++;
    }
    throw NoOccurrenceIsFound();
}
