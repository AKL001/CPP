/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:48 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/07 17:06:01 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
}

void Harl::debug(void) 
{ 
    std::cout << "[DEBUG]" << '\n'; 
    std::cout << "I love having extra bacon" << '\n' << std::endl;
}
void Harl::info(void) { std::cout << "[INFO]" << std::endl; 
    std::cout << "I cannot believe adding extra bacon costs more money" << '\n' << std::endl;
}
void Harl::warning(void) { std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << '\n' << std::endl;
}
void Harl::error(void) { std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n' << std::endl;
}

Level Harl::compLevel(const std::string &level)
{
    if (level == "DEBUG" || level == "debug") {return DEBUG;}
    else if (level == "INFO" || level == "info") {return INFO;}
    else if (level == "WARNING" || level == "warning") {return WARNING;}
    else if (level == "ERROR" || level == "error") {return ERROR;}
    else {return COMPLAIN ;}
}

void Harl::complain(const std::string &level)
{   
    void (Harl::*complain[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    switch (compLevel(level))
    {
    case DEBUG:
        (this->*complain[0])();
    case INFO:
        (this->*complain[1])();
    case WARNING:
        (this->*complain[2])();
    case ERROR:
        (this->*complain[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}