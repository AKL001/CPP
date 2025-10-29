#pragma once 
#include "Bureaucrat.hpp"
#include <exception>

class Form
{
    private:
        const std::string _name;
        bool    _signed;
        const int    _gradeToSign;
        const int    _gradeToExecute;
    public:
        Form();
        Form(std::string &name,bool sign,int gradeToSign,int gradeToExecute);
        Form(const Form& cp);
        Form& operator=(const Form& cp);
        ~Form();
        /* gettes && setters*/
        const std::string &getName(void) const;
        bool    isSigned(void)const;
        int getGradeToSign()const;
        int getGradeToExecute()const;

        void    setSigned(bool t);

        /* member functions*/
        void beSigned(Bureaucrat &b);   


        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};
std::ostream& operator<<(std::ostream &out,const Form &f);