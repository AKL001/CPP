#include "Span.hpp"
#include <exception>
#include <ostream>
#include <vector>
#include <iostream>

std::ostream &out = std::cout;

int main()
{

    std::vector<int> v;
    v.push_back(17);
        v.push_back(6);
        v.push_back(3);
        v.push_back(11);

    int t[] = {17,6,3,11};
    (void)t;
    Span sp = Span(5);    
    
    try
    {
        // sp.addNumber(17);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(11);
        sp.addNumber(v.begin(),v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }catch(std::exception &e)
    {
        out << e.what() << std::endl;
    }

    // try
    // {
    //     out << sp[5] << std::endl;
    // }catch(std::exception &e)
    // {
    //     out << e.what() << std::endl;
    // }
    
}