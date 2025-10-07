/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:21:01 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:21:02 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (!N)
        return  NULL;
    Zombie *zombies = new Zombie[N];

    for (int i = 0; i < N ;i++)
    {
        zombies[i].setName(name);
    }
    return zombies;
}