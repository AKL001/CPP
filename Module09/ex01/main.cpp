#include "RPN.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    try
    {
        syntax_checker(argv[1]);
        int result = RPN_calculator(argv[1]);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
