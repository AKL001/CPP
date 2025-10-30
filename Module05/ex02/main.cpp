#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 40);
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "--- Trying to execute unsigned forms ---" << std::endl;
        try { shrub.execute(boss); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { robo.execute(boss); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { pardon.execute(boss); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

        std::cout << "\n--- Signing forms with boss ---" << std::endl;
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        std::cout << "\n--- Executing forms with different ranks ---" << std::endl;

        std::cout << "\n>> Shrubbery by Mid" << std::endl;
        mid.executeForm(shrub);

        std::cout << "\n>> Robotomy (2 attempts to see different result)" << std::endl;
        mid.executeForm(robo);
        mid.executeForm(robo);

        std::cout << "\n>> Presidential Pardon" << std::endl;
        boss.executeForm(pardon);

        std::cout << "\n--- Testing low grade failure ---" << std::endl;
        try { low.signForm(shrub); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { low.executeForm(shrub); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }
    catch (std::exception &e)
    {
        std::cout << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
