#include "AForm.hpp"

AForm::AForm(): _name("UNKNOWN"), _signed(false),_gradeToSign(150),_gradeToExecute(150){}

AForm::AForm(const std::string &name,bool sign,int gradeToSign,int gradeToExecute) : _name(name),_signed(sign),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& cp) : _name(cp._name),_signed(cp._signed),_gradeToSign(cp._gradeToSign),_gradeToExecute(cp._gradeToExecute){}   

AForm& AForm::operator=(const AForm& cp)
{
    if (this != &cp)
        _signed = cp._signed;
    return *this;
}

AForm::~AForm(){}

/* gettes && setters*/
const std::string& AForm::getName(void) const
{
    return _name;
}

bool    AForm::isSigned(void) const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute()const
{
    return _gradeToExecute;
}

void    AForm::setSigned(bool t)
{
    _signed = t;
}

/* member functions*/
void AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void    AForm::validateExecution(const Bureaucrat &excutor) const
{
    if(!_signed)
        throw FormNotSignedException();
    if (excutor.getGrade() > _gradeToExecute)
        throw GradeTooLowException(); 
}

/* exceptions */
const char* AForm::GradeTooHighException::what() const throw ()
{
    return "Bureaucrat grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw ()
{
    return "Bureaucrat grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form need to be signed before execution";
}

std::ostream& operator<<(std::ostream &out,const AForm &f)
{
    out << "AForm name: " << f.getName() << " GradeToExecute: " << f.getGradeToExecute() << " GradeToSigne: " << f.getGradeToSign() << " is Signed: " << f.isSigned() << std::endl;
    return out;
}