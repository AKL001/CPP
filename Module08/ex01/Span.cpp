#include "Span.hpp"
#include <cstddef>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>


Span::Span() : _size(0){}

Span::Span(unsigned int n) : _size(n)
{
    // pre allocate the memory for the vector in memory
    _span.reserve(_size);
}

Span::Span(const Span& cp)
{
    *this = cp;    
}

Span& Span::operator=(const Span& cp){
    
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

Span::~Span(){}

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

    // std::vector<int> sorted = _span;
    
    // std::sort(sorted.begin(),sorted.end());
    unsigned int s  = UINT_MAX;
    for (unsigned int i =1 ; i < _span.size(); ++i)
    {
        unsigned int diff = std::abs(_span[i] - _span[i - 1]);
        if (diff  < s)
            s = diff;
    }
    return s;
}
// 3 6 9 11 17
// 6 3 17 9 11
// std::vector<int> sorted = _span;
// std::sort(sorted.begin(),sorted.end());
// return std::abs(sorted[0] - sorted[sorted.size() - 1]);
unsigned int Span::longestSpan()
{
    if (this->_span.size() < 2)
        throw NotEnoughNumbersTofind();
    std::vector<int>::iterator min_it = std::min_element(_span.begin(),_span.end());
    std::vector<int>::iterator max_it = std::max_element(_span.begin(),_span.end());
    return (static_cast<unsigned int>(std::abs(*max_it - *min_it)));
}

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