/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:48 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:49 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
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
    switch (compLevel(level))
    {
    case DEBUG:
        printHarl(DEBUG);
        break;
    case INFO:
        printHarl(INFO);
        break;
    case WARNING:
        printHarl(WARNING);
        break;
    case ERROR:
        printHarl(ERROR);
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}

void Harl::printHarl(int level)
{
    void (Harl::*complain[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = level; i < 4 ; i++)
    {
        (this->*complain[i])();
    }
}