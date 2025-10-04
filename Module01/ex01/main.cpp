/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:20:49 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:20:50 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie  *zombies = zombieHorde(N, "ZombieHorde");

    for (int i = 0; i < N ; i++)
    {   
        std::cout << "[" << i << "] ";
        zombies[i].annonce();
    }
    // free all the memory allocated [] cuz we allocated an array 
    delete[] zombies;
    return 0;
}