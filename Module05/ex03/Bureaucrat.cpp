#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name,int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cp) : _name(cp._name) , _grade(cp._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cp)
{
    if (this != &cp)
        _grade = cp._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()   
{       
}

/* getters and setters*/
const std::string& Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void  Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw  GradeTooHighException();
    else if (grade > 150)
        throw  GradeTooLowException();
    _grade = grade;
}

/* exceptions */
const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "Grade Too Low";
}

/* increments && Decrements */

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

std::ostream& operator<<(std::ostream &out,const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &Aform)
{   
    try
    {
        Aform.beSigned(*this);
        std::cout << _name << " signed " << Aform.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't sign " << Aform.getName() << " becasue " << e.what() << std::endl;
    }
}


void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}