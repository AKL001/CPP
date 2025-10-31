#pragma once 
#include "AForm.hpp"
#include <exception>

class Intern
{

    public:
        Intern();
        Intern(const Intern&cp);
        Intern& operator=(const Intern&cp);
        ~Intern();
        
        // funtion member
        AForm* makeForm(const std::string& formName,const std::string& formTarget);

        class FormDoesntExist : public std::exception
        {
            public:
                const char* what() const throw ();
        };
};
AForm* createSCF(const std::string& target);
AForm* createRRF(const std::string& target);
AForm* createPPF(const std::string& target);