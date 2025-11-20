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
        // template get called when we need to do multiple isertion       
        template <typename IT>
        void addNumber(IT begin,IT end)
        {
            // distance return distance between iterators
            // for random access iterator is uses @- else it uses the opeator++
            unsigned int dis =  std::distance(begin,end);
            if (_span.size() + dis > _size)
                throw CantAddNumberMaxLenReached();
            _span.insert(_span.end(), begin, end);
        }

        unsigned int shortestSpan();
        unsigned int longestSpan();
        /*
            making my class own iterator for my class so we can call sp.begin() or sp.end()
            iterators are just pointers that make ur life easy
        */
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
        int capacity();
        unsigned int size();

        /*-----------------------------------------*/
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
};