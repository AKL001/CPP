#include "Form.hpp"

Form::Form(): _name("UNKNOWN"), _signed(false),_gradeToSign(150),_gradeToExecute(150)
{
}

Form::Form(const std::string &name,bool sign,int gradeToSign,int gradeToExecute) : _name(name),_signed(sign),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& cp) : _name(cp._name),_signed(cp._signed),_gradeToSign(cp._gradeToSign),_gradeToExecute(cp._gradeToExecute)
{
}   

Form& Form::operator=(const Form& cp)
{
    if (this != &cp)
        _signed = cp._signed;
    return *this;
}

Form::~Form()
{
    
}
/* gettes && setters*/
const std::string& Form::getName(void) const
{
    return _name;
}

bool    Form::isSigned(void) const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute()const
{
    return _gradeToExecute;
}

void    Form::setSigned(bool t)
{
    _signed = t;
}

/* member functions*/
void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

/* exceptions */
const char* Form::GradeTooHighException::what() const throw ()
{
    return "Bureaucrat grade is too high";
}

const char* Form::GradeTooLowException::what() const throw ()
{
    return "Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream &out,const Form &f)
{
    out << "Form name: " << f.getName() << " GradeToExecute: " << f.getGradeToExecute() << " GradeToSigne: " << f.getGradeToSign() << " is Signed: " << f.isSigned() << std::endl;
    return out;
}