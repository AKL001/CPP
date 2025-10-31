#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        // Valid forms
        AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");

        // Sign & execute
        boss.signForm(*f1);
        boss.executeForm(*f1);

        boss.signForm(*f2);
        boss.executeForm(*f2);

        boss.signForm(*f3);
        boss.executeForm(*f3);

        try
        {
            AForm* bad = someRandomIntern.makeForm("unknown form", "Nobody");
            (void)bad;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        delete f1;
        delete f2;
        delete f3;
    }
    catch (std::exception &e)
    {
        std::cout << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
