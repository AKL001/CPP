#include <cfloat>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
// #include "PhoneBook.hpp"

std::string trim(const std::string &s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    return s.substr(start, end - start);
}


int main(int ac,char **av) {
    PhoneBook pb;
    (void)av;
    if (ac != 1)
     return (std::cout << "Program must have no arguments" << std::endl,1);

    while (1)
    {
        std::string command;
        std::cout << "Choose one command: ADD, SEARCH, or EXIT" << std::endl;
        std::getline(std::cin, command);
        // for ctrl + D , eof ;
        if(std::cin.eof())
        {
            std::cout << "Exiting..." << std::endl;
            break; // leave the loop
        }
        command = trim(command);
        if (command == "ADD")
            std::cout << "You chose ADD" << std::endl;
        else if (command == "SEARCH")
            std::cout << "You chose SEARCH" << std::endl;
        else if (command == "EXIT")
        {
            std::cout << "Exiting..." << std::endl;
            break; // leave the loop
        }
        else
            std::cout << "Invalid command. Try again." << std::endl;
    }
    return 0;
}