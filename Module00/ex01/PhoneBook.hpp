#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    Contact contacts[8];
    // int     _id;
    int     count;


public:
    PhoneBook() : count(0) {}

    void addContact(const Contact& c) {
        if (count < 8) {
            contacts[count] = c;
            count++;
        } else {
            std::cout << "PhoneBook is full!" << std::endl;
        }
    }

    void displayContacts() const 
    {
        for (int i = 0; i < count; i++) {
            std::cout << "Contact " << i + 1 << ":\n";
            std::cout << "  First Name: " << contacts[i].getFirstName() << "\n";
            std::cout << "  Last Name: " << contacts[i].getLastName() << "\n";
            std::cout << "  Nickname: " << contacts[i].getNickName() << "\n";
            std::cout << "  Phone: " << contacts[i].getPhoneNumber() << "\n";
            std::cout << "  Darkest Secret: " << contacts[i].getDarkestSecret() << "\n\n";
        }
    }

};



#endif