#pragma once 
#include "AForm.hpp"


class ShrubberyCreationForm :public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm&cp);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&cp);
        ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};  