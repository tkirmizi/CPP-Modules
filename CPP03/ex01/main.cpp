/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:07:47 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void objShow(ClapTrap &obj)
{
	std::cout
	<< std::setw(10) << std::right << obj.getName() << "|"
	<< std::setw(10) << std::right << obj.getHit() << "|"
	<< std::setw(10) << std::right << obj.getEnergy() << "|"
	<< std::setw(10) << std::right << obj.getAttack() << "|"
	<< std::endl;
}

int main(){
	std::cout << "\n === Scavtrap and Claptrap Constructor Test ===" << std::endl;
	ScavTrap objA ("Warrior");
	std::cout << "\n === Scavtrap Copy Constructor Test ===" << std::endl;
	ScavTrap objB = objA;
	std::cout << "\n === Scavtrap Copy Assignment Operator Test ===" << std::endl;
	objA = objB;
	std::cout << "\n === Objects Value's Test === " << std::endl;
	std::cout << "      Name|Hit Points|Energy    |Attack    |" << std::endl;
	objShow(objA);
	objShow(objB);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "\n=== Fucntions Test ===" << std::endl;
	objA.attack("Enemy");
	objShow(objA);
	std::cout << "------------------------------------------" << std::endl;
	objB.takeDamage(15);
	objShow(objB);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "\n===Scavtrap Gate keeper Test ===" << std::endl;
	objA.guardGate();
	std::cout << "\n=== Scavtrap and Claptrap Destructon Test ===" << std::endl;
}