/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:04:43 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 10:27:23 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(void){
	std::cout
	<< this->name << " attacks with their " << this->weapon.getType()
	<< std::endl;
}

HumanA::HumanA(std::string newName, Weapon &newWeapon) :  name(newName), weapon(newWeapon){};
