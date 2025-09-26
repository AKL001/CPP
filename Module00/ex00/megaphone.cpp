/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:37:57 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/26 16:37:58 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int main(int ac,char **av)
{
    int i , j;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0; 
    }
    else
    {
        i = 0;
        while (av[++i])
        {
            j = -1;
            while(av[i][++j])
                std::cout << static_cast<char>(std::toupper(av[i][j]));
            // used static_cast for type safety instead of C_type cast
        }
    }
    std::cout << '\n';
    return 0;
}