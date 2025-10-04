/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:55 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:56 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"



int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "./harlFilter <complain type>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);
    
}