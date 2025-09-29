#include <iostream>

// ANSI color codes
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

int main()
{
    std::string _message = "HI THIS IS BRAIN";

    // pointer to message string 
    std::string *stringPTR = &_message;

    // reference to message string 
    std::string &stringREF = _message;

    std::cout << CYAN << "=== ADDRESSES ===" << RESET << std::endl;
    std::cout << YELLOW  << "String address:           " 
              << RESET << &_message << std::endl;
    std::cout << YELLOW  << "Address held by stringPTR:" 
              << RESET << stringPTR << std::endl;
    std::cout << YELLOW  << "Address held by stringREF:" 
              << RESET << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << CYAN << "=== VALUES ===" << RESET << std::endl;
    std::cout << GREEN  << "message:     " << RESET << _message << std::endl;
    std::cout << GREEN  << "stringPTR:   " << RESET << *stringPTR << std::endl;
    std::cout << GREEN  << "stringREF:   " << RESET << stringREF << std::endl;

    return 0;
}
