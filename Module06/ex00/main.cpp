#include "ScalarConverter.hpp"


int main(int ac,char **av)
{
    if (ac != 2)
        return ((std::cout << "./convert <number>" << std::endl),1);
    ScalarConverter::convert(av[1]);    
    return 0;
}