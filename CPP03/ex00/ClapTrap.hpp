/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:34:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:19:38 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

class ClapTrap{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackPoints;
	public:
		ClapTrap(); // Constructron
		ClapTrap(std::string name); // Constructton
		~ClapTrap(); // Destructon
		ClapTrap(const ClapTrap& other); // Copy constructron
		ClapTrap& operator=(const ClapTrap &other); // Copy assignment operator

		// Member functions
		void attack(const std::string& target);	
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Getter Functions
		std::string&	getName(void);
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttack(void) const;
		
};


#endif