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
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackPoints;
	public:
		ClapTrap(); // constructor
		ClapTrap(std::string name); // constructor
		ClapTrap(std::string name, int hit, int energy, int attack); // constructor
		virtual ~ClapTrap(); // destructor
		ClapTrap(const ClapTrap& other); // copy constructor
		ClapTrap& operator=(const ClapTrap &other); // copy assignment operator
		void attack(const std::string& target); 
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string		getName(void) const;
		int				getHit(void) const;
		int				getEnergy(void) const;
		int				getAttack(void) const;
		// void		setName(std::string name);
		// void		setHit(int hit);
		// void		setEnergy(int energy);
		// void		setAttack(int attack);
};


#endif