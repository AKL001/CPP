/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:33 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/07 17:03:09 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>
#include <string>

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

void Harl::complain(std::string level)
{
    void (Harl::*complain[4])(void) = { &Harl::debug , &Harl::info , &Harl::warning, &Harl::error }; 
    
    std::string names[4] = {"debug" , "info" , "warning", "error"};
    
    for (int i = 0; i < 4; i++)
    {
        if (names[i] == level)
        {
            (this->*complain[i])();
            return;
        }
    }

}