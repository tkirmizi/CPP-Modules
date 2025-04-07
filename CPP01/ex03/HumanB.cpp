/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:23:42 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 11:35:33 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string newName): name(newName){};

void HumanB::setWeapon(Weapon &newWeapon){
	weapon  = &newWeapon;
}

void HumanB::attack(void){
	std::cout
	<< this->name << " attacks with their " << (*weapon).getType()
	<< std::endl;
}
