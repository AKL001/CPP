/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:53 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/07 17:05:41 by ablabib          ###   ########.fr       */
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
        void debug(void);
        void info(void); 
        void warning(void);
        void error(void);

    public:
        Harl();
        void complain(const std::string &level);
        Level compLevel(const std::string &level);
};


#endif