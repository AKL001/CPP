#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

std::ostream &out = std::cout;


const char* NoOccurrenceIsFound::what() const throw()
{
    return "No occurrence of the value was found in the container.";
}

#include <list>
int main()
{
   std::list<int> l; 
    l.push_back(0);
    l.push_back(2);
    l.push_back(1);
    try
    {
        out << "Found in possition : " << easyfind(l, 2)  << std::endl;
    }
    catch(std::exception &e)
    {
        out  << e.what() << std::endl ;
    }

    std::vector<int> v;
    v.push_back(42);
    v.push_back(44);
    v.push_back(123123);
    try
    {
        out << easyfind(v, 888)  << std::endl;
    }
    catch(std::exception &e)
    {
        out  << e.what() << std::endl ;
    }

}