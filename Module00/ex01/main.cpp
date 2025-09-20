#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
// #include "PhoneBook.hpp"




int main() {
    PhoneBook pb;
    
    // Add 8 contacts
    pb.addContact(Contact("John", "Doe", "JD", "Loves pizza", "123456789"));
    pb.addContact(Contact("Jane", "Smith", "JS", "Afraid of cats", "987654321"));
    pb.addContact(Contact("Alice", "Johnson", "Ally", "Secret gamer", "555111222"));
    pb.addContact(Contact("Bob", "Brown", "Bobby", "Hates onions", "444333222"));
    pb.addContact(Contact("Charlie", "Davis", "Chaz", "Sings in shower", "333222111"));
    pb.addContact(Contact("Diana", "Miller", "Di", "Speaks 5 languages", "111222333"));
    pb.addContact(Contact("Eve", "Wilson", "Evie", "Never sleeps", "666777888"));
    pb.addContact(Contact("Frank", "Taylor", "Franky", "Scared of clowns", "999888777"));

    // Display all contacts
    pb.displayContacts();

    return 0;
}