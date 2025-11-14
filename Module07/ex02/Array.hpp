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
        ~Array();
        // operator overloading 
        Array& operator=(const Array& cp);
        T& operator[](unsigned int index);
        // for a const array so  the compiler would know it
        const T& operator[](unsigned int index) const;
        // member functions
        unsigned int  size() const;
        // trowing execptions
        class CantAccessElementOutBound : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

#include "Array.tpp"