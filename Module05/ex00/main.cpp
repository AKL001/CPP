#include "Bureaucrat.hpp"
#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
    try
    {
        std::cout << GREEN << "Creating Bureaucrats..." << RESET << std::endl;
        Bureaucrat s("Hamid", 1);        
        Bureaucrat d(s);                   
        Bureaucrat aziz("Akhannouch", 2); 

        std::cout << BLUE << s << RESET << std::endl;
        std::cout << BLUE << d << RESET << std::endl;
        std::cout << BLUE << aziz << RESET << std::endl;

        std::cout << YELLOW << "\nIncrementing grades..." << RESET << std::endl;
        s.incrementGrade(); 
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << RED << "Caught High Exception: " << e.what() << RESET << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << RED << "Caught Low Exception: " << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << YELLOW << "\nTesting Low Grade..." << RESET << std::endl;
        Bureaucrat low("John", 150);
        std::cout << BLUE << low << RESET << std::endl;
        low.decrementGrade(); 
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << RED << "Caught High Exception: " << e.what() << RESET << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << RED << "Caught Low Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
