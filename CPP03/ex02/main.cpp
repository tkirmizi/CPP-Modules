/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:15:28 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void objShow(ClapTrap &obj)
{
	std::cout << "      Name|Hit Points|Energy    |Attack    |" << std::endl;
	std::cout
	<< std::setw(10) << std::right << obj.getName() << "|"
	<< std::setw(10) << std::right << obj.getHit() << "|"
	<< std::setw(10) << std::right << obj.getEnergy() << "|"
	<< std::setw(10) << std::right << obj.getAttack() << "|"
	<< std::endl;
	std::cout << "------------------------------------------" << std::endl;

}

int main()
{
	std::cout << "\n=== TESTING FRAGTRAP VS SCAVTRAP ===" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << std::endl;

	ScavTrap scav("Guardian");
	ScavTrap scav2;
	FragTrap frag("Warrior");

	std::cout << "\n=== INITIAL VALUES TEST ===" << std::endl;
	std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
	std::cout << "HP: " << scav.getHit() << std::endl;        
	std::cout << "Energy: " << scav.getEnergy() << std::endl;  
	std::cout << "Attack: " << scav.getAttack() << std::endl;  

	std::cout << "\nFragTrap " << frag.getName() << " stats:" << std::endl;
	std::cout << "HP: " << frag.getHit() << std::endl;        
	std::cout << "Energy: " << frag.getEnergy() << std::endl;  
	std::cout << "Attack: " << frag.getAttack() << std::endl;  

	std::cout << "\n=== SPECIAL ABILITIES TEST ===" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n=== COMBAT TEST ===" << std::endl;
	scav.attack("Enemy1");
	frag.attack("Enemy2");

	std::cout << "\n=== DAMAGE AND REPAIR TEST ===" << std::endl;
	std::cout << std::endl;
	scav.takeDamage(40);
	std::cout << std::endl;
	objShow(scav);
	frag.takeDamage(80);
	std::cout << std::endl;
	objShow(frag);
	scav.beRepaired(20);
	std::cout << std::endl;
	objShow(scav);
	frag.beRepaired(20);
	objShow(frag);

	std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
	FragTrap frag2(frag);

	std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
	scav2 = scav;
	frag2 = frag;

	std::cout << "\n=== END OF TESTS ===" << std::endl;
	return 0;
}