#pragma once 
#include "Bureaucrat.hpp"
#include <exception>

class AForm
{
    private:
        const std::string _name;
        bool    _signed;
        const int    _gradeToSign;
        const int    _gradeToExecute;
    public:
        AForm();
        AForm(const std::string &name,bool sign,int gradeToSign,int gradeToExecute);
        AForm(const AForm& cp);
        AForm& operator=(const AForm& cp);
        ~AForm();
        
        /* gettes && setters*/
        const std::string &getName(void) const;
        bool    isSigned(void)const;
        int getGradeToSign()const;
        int getGradeToExecute()const;
        void    setSigned(bool t);


        /* member functions*/
        void beSigned(Bureaucrat &b);   
        virtual void execute(Bureaucrat const & executor) const = 0;
        void    validateExecution(const Bureaucrat &excutor) const;

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream &out,const AForm &f);