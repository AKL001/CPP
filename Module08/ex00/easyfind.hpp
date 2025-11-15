#pragma  once 
#include <cstddef>


template <typename T>
T easyfind(T& x,int a)
{
    for (size_t i = 0; i < x.size();i++)
    {
        if(x[i] == a)
            return x[i];
    }
    // throw exception
}