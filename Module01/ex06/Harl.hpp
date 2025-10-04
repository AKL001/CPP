/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:53 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:53 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

enum Level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    COMPLAIN
};


class Harl
{
    private:
        void debug(void) 
        { 
            std::cout << "[DEBUG]" << '\n'; 
            std::cout << "I love having extra bacon" << '\n' << std::endl;
        }
        void info(void) { std::cout << "[INFO]" << std::endl; 
            std::cout << "I cannot believe adding extra bacon costs more money" << '\n' << std::endl;
        }
        void warning(void) { std::cout << "[WARNING]" << std::endl;
            std::cout << "I think I deserve to have some extra bacon for free." << '\n' << std::endl;
        }
        void error(void) { std::cout << "[ERROR]" << std::endl;
            std::cout << "This is unacceptable! I want to speak to the manager now." << '\n' << std::endl;
        }

    public:
        Harl();
        void complain(const std::string &level);
        Level compLevel(const std::string &level);
        void printHarl(int level);
};


#endif