#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Uknown Presidential",false,145,137), _target("Uknown Target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm",false,145,137), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cp) : AForm(cp) , _target(cp._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cp)
{
    if(this != &cp)
        AForm::operator=(cp);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}