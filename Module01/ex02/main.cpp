/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:21:24 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:21:25 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// ANSI color codes
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

// The goal is to understand the difference between:
//   - a POINTER (*): stores the memory address of a variable, 
//     can be reassigned to point to another variable, 
//     and can be nullptr (pointing to nothing).
//   - a REFERENCE (&): an alias to an existing variable, 
//     cannot be changed to refer to another one once initialized,
//     and cannot be null.
//
// In practice, both give access to the same value, but their
// behavior and usage are different. This exercise demonstrates
// that both pointers and references can access the same object.

int main()
{
    std::string _message = "HI THIS IS BRAIN";

    // pointer to message string 
    std::string *stringPTR = &_message;

    // reference to message string 
    std::string &stringREF = _message;

    std::cout << CYAN << "=== ADDRESSES ===" << RESET << std::endl;
    std::cout << YELLOW  << "String address:           " 
              << RESET << &_message << std::endl;
    std::cout << YELLOW  << "Address held by stringPTR:" 
              << RESET << stringPTR << std::endl;
    std::cout << YELLOW  << "Address held by stringREF:" 
              << RESET << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << CYAN << "=== VALUES ===" << RESET << std::endl;
    std::cout << GREEN  << "message:     " << RESET << _message << std::endl;
    std::cout << GREEN  << "stringPTR:   " << RESET << *stringPTR << std::endl;
    std::cout << GREEN  << "stringREF:   " << RESET << stringREF << std::endl;

    return 0;
}
