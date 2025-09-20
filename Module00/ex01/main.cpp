#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
// #include "PhoneBook.hpp"




int main() {
    PhoneBook pb;
    
    // Add 8 contacts
     Contact c1("John", "Doe", "JD", "Loves pizza", "123456");
    Contact c2("Jane", "Smith", "JS", "Afraid of heights", "987654");

    pb.addContact(c1);
    pb.addContact(c2);

    pb.displayContacts();

    return 0;
}