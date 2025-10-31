#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern&cp)
{
    *this = cp;
}

Intern& Intern::operator=(const Intern&cp)
{
    (void)cp;
    return *this;
}

AForm* createPPF(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* createRRF(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

AForm* createSCF(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

const char* Intern::FormDoesntExist::what() const throw ()
{
    return "Form Doesn't Exist";
}

// funtion member
AForm* Intern::makeForm(const std::string& formName,const std::string& formTarget)
{
    const std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
        };
    
    AForm* (*forms[3])(const std::string&) = {
        &createPPF, &createRRF, &createSCF
        };

    for(int i=0; i < 3;i++)
    {
        if(formName == names[i])
        {
            std::cout << "Intern creates "<< names[i] << std::endl;
            return (*forms[i])(formTarget);
        }
    }
    throw FormDoesntExist();
    return NULL;
}