/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:50:22 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/15 19:59:22 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(); // other msg 
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap& cp);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap(); // other msg 

        void attack(const std::string& target);
        void guardGate();
};
#endif