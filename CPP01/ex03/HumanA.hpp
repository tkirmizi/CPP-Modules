/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:02:58 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 11:43:56 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include "Weapon.hpp"

class HumanA{
	private:
		std::string	name;
		Weapon		&weapon; // ref to have copy from beginning
	public:
		void attack(void);
		HumanA(std::string newName, Weapon &newWeapon);
};

#endif