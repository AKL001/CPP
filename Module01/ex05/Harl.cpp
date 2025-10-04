/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:33 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:34 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
    -syntax of pointer to member function :  
    return_type (ClassName::*pointer_name)(argument_types) = 
    &ClassName::member_function;

*/

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "[DEBUG] I love debugging!\n";
}

void Harl::info(void)
{
    std::cout << "[INFO] Some info.\n"; 
}

void Harl::warning(void)
{
    std::cout << "[WARNING] Watch out!\n"; 
}

void Harl::error(void)
{
    std::cout << "[ERROR] Something went wrong!\n";
}

Level Harl::getLevel(const std::string& level) {
    if (level == "debug")    return DEBUG;
    else if (level == "info")    return INFO;
    else if (level == "warning") return WARNING;
    else if (level == "error")   return ERROR;  
    else
        return UNKNOWN;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptrDebug)(void) = &Harl::debug;
    void (Harl::*ptrInfo)(void) = &Harl::info;
    void (Harl::*ptrWarning)(void) = &Harl::warning;
    void (Harl::*ptrError)(void) = &Harl::error;
    
    switch (getLevel(level))
    {
    case DEBUG:
        (this->*ptrDebug)();
        break;
    case INFO:
        (this->*ptrInfo)();
        break;
    case WARNING:
        (this->*ptrWarning)();
        break;
    case ERROR:
        (this->*ptrError)();
        break;
    default:
        std::cout << "Unknown level!" << std::endl;
        break;
    }

}