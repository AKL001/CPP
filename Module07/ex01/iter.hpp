#pragma  once 
#include <iostream>

template <typename T>
void print(T &value)    
{
    std::cout << value << std::endl;
}

template <typename T>
void iter(T *add,const int len,void (*func)(T&))
{
    for (int i = 0; i < len ; i++)
        func(add[i]);
}

// overloading for the const
template <typename T>
void iter(T *add,const int len,void (*func)(const T&))
{
    for (int i = 0; i < len ; i++)
        func(add[i]);
}
