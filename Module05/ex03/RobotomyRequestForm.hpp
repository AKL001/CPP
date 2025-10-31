#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm& cp);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& cp);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};