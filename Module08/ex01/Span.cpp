#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <climits>


Span::Span() : _size(0){}

Span::~Span(){}

Span::Span(unsigned int n) : _size(n)
{
    // pre allocate the memory for the vector in memory
    // std::cout << "size is = " << _span.capacity() << " n is = " << n  << std::endl; 
    // we can use _span.capacity() to check the capacity
    _span.reserve(_size);
}

Span::Span(const Span& cp)
{
    *this = cp;    
}

Span& Span::operator=(const Span& cp)
{
    if (this != &cp)
    {
        _size = cp._size; 
        _span = cp._span;
    }
    return *this;
}

const int& Span::operator[](const unsigned int index) const
{
    if (index >= _span.size())
        throw IndexOutOfBound();
    return _span[index];
}


/* member functions */
void Span::addNumber(int n)
{
    if (_span.size() < _size)
        _span.push_back(n);
    else
        throw CantAddNumberMaxLenReached();
}

unsigned int Span::shortestSpan()
{
    if (this->_span.size() < 2)
        throw NotEnoughNumbersTofind();
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(),sorted.end());
    unsigned int s  = UINT_MAX;
    for (unsigned int i =1 ; i < sorted.size(); ++i)
    {
        long diff = static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]);
        if (static_cast<unsigned int>(diff)  < s)
            s = static_cast<unsigned int>(diff);
    }
    return s;
}
/*
    1> we can also use sorted and compair the first element with last but that would take time complexity of 
        n(log O)
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(),sorted.end());
    return std::abs(sorted[0] - sorted[sorted.size() - 1]);
*/
unsigned int Span::longestSpan()
{
    if (this->_span.size() < 2)
        throw NotEnoughNumbersTofind();
    std::vector<int>::iterator min_it = std::min_element(_span.begin(),_span.end());
    std::vector<int>::iterator max_it = std::max_element(_span.begin(),_span.end());
    return (static_cast<unsigned int>(static_cast<long>(*max_it) - static_cast<long>(*min_it)));
}

/* overriding */
const char *Span::CantAddNumberMaxLenReached::what() const throw()
{
    return "Caught : Cant Add More Numbers max len Reached";
}

const char *Span::IndexOutOfBound::what() const throw()
{
    return "Caught : Index Out Of Bound";
}

const char *Span::NotEnoughNumbersTofind::what() const throw()
{
    return "Caught : Not Enough Number To Find";
}