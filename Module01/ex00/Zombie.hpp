/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:20:09 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:20:34 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{ 
  private:
    std::string _name;

  public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
    
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif // ZOMBIE_HPP