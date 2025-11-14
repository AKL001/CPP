#pragma once
#include <exception>


template <class T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(const unsigned int n);
        Array(const Array& cp);
        Array& operator=(const Array& cp);
        ~Array();

    unsigned int  size() const;

    class CantAccessElementOutBound : public std::exception
    {
        public:
            const char * what() const throw();
    };
};

#include "Array.tpp"