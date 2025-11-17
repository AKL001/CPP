#pragma  once 
#include <exception>
#include <vector>
#include <iostream>


class Span
{
    private:
        std::vector<int>  _span;
        unsigned int _size;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& cp);
        Span& operator=(const Span& cp);
        ~Span();

        // operator overlaoding for testing 
        // getter i dont want to change the value of the index
        const int& operator[](const unsigned int index) const;


        // member functions 
        void addNumber(int n);// fill the Span N ?? is it the range of the span of the int to add here ? 
        
        unsigned int shortestSpan();
        unsigned int longestSpan();


        class IndexOutOfBound : public std::exception
        {
            public:
                const char * what() const throw();
        };

        class CantAddNumberMaxLenReached : public std::exception
        {
            public:
                const char * what() const throw();
        };

        class NotEnoughNumbersTofind : public std::exception
        {
            public:
                const char * what() const throw();
        };
        // member function to add multiple numbers at the same time;
};