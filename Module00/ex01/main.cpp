/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:38:13 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/26 16:38:15 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfloat>
#include <iostream>
#include "PhoneBook.hpp"

int main(int ac,char **av) {
    PhoneBook pb;
    (void)av;

    if (ac != 1)
        return (std::cout << RED << "Program must have no arguments" 
                          << RESET << std::endl, 1);

    while (1)
    {
        std::string command;
        std::cout << CYAN << "Choose one command: " 
                  << GREEN << "ADD" << RESET << ", "
                  << YELLOW << "SEARCH" << RESET << ", or "
                  << RED << "EXIT" << RESET << std::endl;

        std::getline(std::cin, command);

        // for ctrl + D , eof ;
        if(std::cin.eof())
        {
            std::cout << RED << "Exiting..." << RESET << '\n';
            break; 
        }

        command = pb.trim(command);

        if (command.empty())
        {
            std::cout << "Empty input, please type a command." << std::endl;
            continue;
        }
        if (command == "ADD")
            pb.newContact(pb);
        else if (command == "SEARCH")
            pb.displayContacts();
        else if (command == "EXIT")
        {
            std::cout << RED << "Exiting..." << RESET << '\n';
            break; 
        }
        else
            std::cout << MAGENTA << "Invalid command. Try again." << RESET << '\n';
    }
    return 0;
}
