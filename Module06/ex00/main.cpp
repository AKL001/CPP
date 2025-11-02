#include "ScalarConverter.hpp"


int main(int ac,char **av)
{
    if (ac != 2)
        return 1;
    std::cout << "=== Converting to char ===" << std::endl;
    ScalarConverter::convert(av[1]);
    
    std::cout << "\n=== Converting to int ===" << std::endl;
    ScalarConverter::convert(av[1]);
    
    std::cout << "\n=== Converting to float ===" << std::endl;
    ScalarConverter::convert(av[1]);
    
    std::cout << "\n=== Converting to double ===" << std::endl;
    ScalarConverter::convert(av[1]);
    
    std::cout << "\n=== Testing special values ===" << std::endl;
    ScalarConverter::convert(av[1]);
    
    return 0;
}