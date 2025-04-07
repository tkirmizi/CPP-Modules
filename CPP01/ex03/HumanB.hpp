/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:21:53 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 17:03:21 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include "Weapon.hpp"

class HumanB{
	private:
		std::string	name;
		Weapon		*weapon; // ptr can be nullptr for non-declared times
	public:
		HumanB(std::string newName);
		void setWeapon(Weapon &newWeapon); // no need in ref
		void attack(void);

};

#endif