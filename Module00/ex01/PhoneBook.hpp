#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class PhoneBook
{
    Contact contacts[8];
    int     _id;
    int     count;


public:
    PhoneBook() : _id(0), count(0) {}

    // std::string getInput(const std::string &prompt);
    static std::string trim(const std::string &s);

    bool getInput(const std::string &prompt, std::string &out);

    void newContact(PhoneBook &pb);
    
    void addContact(const std::string &firstname,const std::string &lastname,const std::string &nickname,const std::string &ds,const std::string &phonenumber);

    // {
    //     if (count < 8) {
    //         contacts[count] = c;
    //         count++;
    //     } else {
    //         std::cout << "PhoneBook is full!" << std::endl;
    //     }
    // }

    void displayContacts() const; 
    // {
    //     for (int i = 0; i < count; i++) {
    //         std::cout << "Contact " << i + 1 << ":\n";
    //         std::cout << "  First Name: " << contacts[i].getFirstName() << "\n";
    //         std::cout << "  Last Name: " << contacts[i].getLastName() << "\n";
    //         std::cout << "  Nickname: " << contacts[i].getNickName() << "\n";
    //         std::cout << "  Phone: " << contacts[i].getPhoneNumber() << "\n";
    //         std::cout << "  Darkest Secret: " << contacts[i].getDarkestSecret() << "\n\n";
    //     }
    // }

};



#endif