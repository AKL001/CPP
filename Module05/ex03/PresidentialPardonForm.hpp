#pragma once 
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& cp);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& cp);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};