#include "Contact.hpp"
#include <iostream>
#include <string>

/*
-default Constructor
Contact::Contact()
{
   std::cout << "Default Constructor..." << std::endl; 
}
-constructor implemntation
Contact::Contact(const std::string& firstname,
                 const std::string& lastname,
                 const std::string& nickname,
                 const std::string& ds,
                 const std::string& phonenumber)
    : _firstname(firstname), _lastname(lastname),
      _nickname(nickname), _darkestsecret(ds),
      _phonenumber(phonenumber)
{}
*/

// default Destructor implementation
Contact::~Contact()
{

}

/*---------------getters-----------------*/
/* we used first const (const std::..) this means the value returned  is const 

for the second const (getFirstNaeme() const ) -> not modify any members of the class  */

const std::string& Contact::getFirstName() const
{
    return  _firstname;
}

const std::string& Contact::getLastName() const
{
    return _lastname;
}
const std::string& Contact::getNickName() const
{
    return _nickname;
}
const std::string& Contact::getDarkestSecret() const
{
    return _darkestsecret;
}
const std::string& Contact::getPhoneNumber() const
{
    return _phonenumber;
}

/*----------setters------------ */
void Contact::setFirstName(std::string firstname)
{
    _firstname = firstname;
}
void Contact::setLastName(std::string lastname)
{
    _lastname =  lastname;
}
void Contact::setNickName(std::string nickname)
{
    _nickname = nickname;
}
void Contact::setDarkestSecret(std::string darkestsecret)
{
    _darkestsecret = darkestsecret;
}
void Contact::setPhoneNumber(std::string phonenumber)
{
    _phonenumber = phonenumber;
}

void Contact::display(int index, bool printHeader) const 
{
        if (printHeader) {
            std::cout << "#___________________________________________#" << std::endl;
            std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
            std::cout << "|----------|----------|----------|----------|" << std::endl;
        }

        std::stringstream ss;
        ss << index;
        std::string idx_str = ss.str();
        idx_str = std::string(10 - idx_str.length(), ' ') + idx_str;

        std::cout << "|" << idx_str
                  << "|" << format_field(_firstname)
                  << "|" << format_field(_lastname)
                  << "|" << format_field(_nickname)
                  << "|" << std::endl;
}

