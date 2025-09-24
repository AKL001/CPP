#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

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
    // valid number
    while (true)
    {
        if (!getInput("Enter phone number: ", phonenumber)) return;

        bool valid = true;
        for (size_t i = 0; i < phonenumber.length(); i++)
        {
            if (!isdigit(phonenumber[i]))
            {
                valid = false;
                break;
            }
        }

        if (valid && phonenumber.length() <= 10)
            break;
        else
            std::cout << RED << "Error: Phone number must contain digits only (max 10 chars). Please try again." << RESET << std::endl;
    }

    pb.addContact(firstname, lastname, nickname, darkestsecret, phonenumber);
}


void PhoneBook::addContact(const std::string &firstname,const std::string &lastname,const std::string &nickname,const std::string &ds,const std::string &phonenumber)
{
    // we need to add some checkes here 
    if (firstname.length() > 50 || lastname.length() > 50 || nickname.length() > 50 || ds.length() > 100 || phonenumber.length() > 10)
    {
        std::cout << CYAN << "Error: One or more fields exceed maximum length!" << RESET << std::endl;
        return;
    }

    Contact c;

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
    bool header = true;
    std::cout << CYAN << "-----------Contacts list:-----------" << RESET << std::endl;
    int start = (_id >= 8) ? _id % 8 : 0;

    for (int i = 0; i < count; i++) 
    {
        int index = (start + i) % 8;
        contacts[index].display(index,header);
        if (header)
            header = false;
    }
    // here we add the search by INDEX
    std::string  search_by_index;
    while (1)
    {
        std::cout << BOLD << "Enter index :" << RESET << std::endl;
        if (std::cin.eof())
            return;
        if (!std::getline(std::cin, search_by_index) || search_by_index.empty())
        {
            std::cout << "Please choose a number!" << std::endl;
            continue;
        }

        // check all characters are digits for  search_by_index
        bool valid = true;
        for (size_t i = 0; i < search_by_index.length(); i++)
        {
            if (!isdigit(search_by_index[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            std::cout << "Please enter a valid number!" << std::endl;
            continue;
        }

        int int_index = atoi(search_by_index.c_str());
        if (int_index < 0 || int_index >= count)
        {
            std::cout << "Number out of range" << std::endl;
            continue;
        }

        int index = (_id >= 8) ? (_id % 8 + int_index) % 8 : int_index;
        contacts[index].display(int_index, true);
        break;
    }
}

