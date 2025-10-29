#pragma once
#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
    //  orthodox form
        Bureaucrat(const std::string name,int grade);
        Bureaucrat(const Bureaucrat& cp);
        Bureaucrat& operator=(const Bureaucrat& cp);
        ~Bureaucrat();

    // getters && setters
        const std::string& getName(void) const;
        void  setGrade(int grade);
        int getGrade(void) const;
    // member functions        
        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form); // this call , Form::beSigned

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw ();
        };
};

std::ostream& operator<<(std::ostream &out,const Bureaucrat &b);

