#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Uknown RobotomyRequestForm",false,72,45), _target("Uknown Target"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm",false,72,45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cp) : AForm(cp) , _target(cp._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cp)
{
    if(this != &cp)
        AForm::operator=(cp);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);

    std::cout << "* Drilling noises: Drrrrrrr... *" << std::endl;

    if ((clock() % 2) == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomization failed." << std::endl;
}