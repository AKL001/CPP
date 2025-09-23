#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>


// PhoneBook::PhoneBook()
// {
// }
// PhoneBook::~PhoneBook()
// {
// }

void PhoneBook::addContact(const Contact& c) 
{
    contacts[_id % 8] = c;
    _id++;
    if (count < 8)
        count++;
}


void PhoneBook::displayContacts() const {
    if (count == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << "Contacts list:" << std::endl;
    int start = (_id >= 8) ? _id % 8 : 0;
    for (int i = 0; i < count; i++) 
    {
        int index = (start + i) % 8;
        std::cout << "[" << i << "] ";
        contacts[index].display();
    }
}
