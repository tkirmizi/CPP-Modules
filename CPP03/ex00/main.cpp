/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 12:37:50 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	std::cout << "\n=== Constructor Test ===" << std::endl;
	ClapTrap obj1 ("taha");
	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	ClapTrap obj2 = obj1;
	std::cout << "\n=== Default Constructor Test ===" << std::endl;
	ClapTrap obj3;
	std::cout << "\n=== Copy Assignment Operator Test ===" << std::endl;
	obj3 = obj2;

	std::cout << "\n\n=== Objects Value's Test ===" << std::endl;
	std::cout
	<< std::setw(10) << std::right << "Name" << "|"
	<< std::setw(10) << std::right << "Health" << "|"
	<< std::setw(10) << std::right << "Energy" << "|"
	<< std::setw(10) << std::right << "Attack" << "|"
	<< std::endl;
	objShow(obj1);
	objShow(obj2);
	objShow(obj3);
	std::cout << "\n\n=== Fucntions Test ===" << std::endl;
	obj1.attack("enemy");
	objShow(obj1);
	std::cout << std::endl;
	obj2.takeDamage(5);
	objShow(obj2);
	std::cout << std::endl;
	obj3.beRepaired(5);
	objShow(obj3);
}