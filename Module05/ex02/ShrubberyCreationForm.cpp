#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Uknown ShrubberyCreationForm",false,145,137), _target("Uknown Target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm",false,145,137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cp) : AForm(cp) , _target(cp._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cp)
{
    if(this != &cp)
        AForm::operator=(cp);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cout << "Error: could not create the shrubbery file" << std::endl;
        return;
    }

    outfile << "        &&& &&  & &&" << std::endl;
    outfile << "    && &\\/&\\|& ()|/ @, &&" << std::endl;
    outfile << "    &\\/(/&/&||/& /_/_&/_&" << std::endl;
    outfile << " &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    outfile << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    outfile << " &&   && & &| &| /& & % ()& /&&" << std::endl;
    outfile << "  ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    outfile << "      &&     \\|||" << std::endl;
    outfile << "              |||" << std::endl;
    outfile << "              |||" << std::endl;
    outfile << "              |||" << std::endl;
    outfile << "        , -=-~  .-^- _" << std::endl;

    outfile.close();
}
