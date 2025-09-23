#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


// PhoneBook::PhoneBook()
// {
// }
// PhoneBook::~PhoneBook()
// {
// }

std::string PhoneBook::trim(const std::string &s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    return s.substr(start, end - start);
}

bool PhoneBook::getInput(const std::string &prompt, std::string &out)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return false; 

        std::string trimmed = trim(input);
        if (!trimmed.empty())
        {
            out = trimmed;
            return true;
        }
        std::cout << RED << "Field cannot be empty. Please try again.\n" << RESET;
    }
}


void PhoneBook::newContact(PhoneBook &pb)
{
    std::string firstname, lastname, nickname, darkestsecret, phonenumber;

    if (!getInput("Enter first name: ", firstname)) return;
    if (!getInput("Enter last name: ", lastname)) return;
    if (!getInput("Enter nickname: ", nickname)) return;
    if (!getInput("Enter darkest secret: ", darkestsecret)) return;
    if (!getInput("Enter phone number: ", phonenumber)) return;

    pb.addContact(firstname, lastname, nickname, darkestsecret, phonenumber);
}


void PhoneBook::addContact(const std::string &firstname,const std::string &lastname,const std::string &nickname,const std::string &ds,const std::string &phonenumber)
{
    Contact c;
    // we need to add some checkes here 

    c.setFirstName(firstname);
    c.setLastName(lastname);
    c.setNickName(nickname);
    c.setDarkestSecret(ds);
    c.setPhoneNumber(phonenumber);

    contacts[_id % 8] = c;
    if (count < 8)
       count++;
    _id++;
}


void PhoneBook::displayContacts() const {
    if (count == 0) {
        std::cout << YELLOW << "PhoneBook is empty." << RESET << std::endl;
        return;
    }

    std::cout << CYAN << "Contacts list:" << RESET << std::endl;
    int start = (_id >= 8) ? _id % 8 : 0;
    for (int i = 0; i < count; i++) 
    {
        int index = (start + i) % 8;
        std::cout << "[" << i << "] ";
        contacts[index].display();
    }
}
