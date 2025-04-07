/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:35:46 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:19:38 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackPoints(0)
	{std::cout << "Default Constructor called" << std::endl;};
	
// Constructors
ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0){std::cout << "Constructor called" << std::endl;};

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackPoints(other._attackPoints)
	{std::cout << "copy constructor worked" <<  std::endl;}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackPoints = other._attackPoints;
	}
	std::cout << "copy assignment operator worked\n";
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(){std::cout << "Destructor called" << std::endl;}

// Member Functions
void ClapTrap::attack(const std::string& target){

	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has either energy or health"  << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout
	<< "ClapTrap " << _name << " attacks " << target
	<< ", causing " << _attackPoints << " points of damage!" <<
	std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	_hitPoints -= amount;
	std::cout
	<< "ClapTrap " << _name << " took damage, causing " << amount << " points of damage!" <<
	std::endl;
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout
		<< "ClapTrap" << _name << " died" <<
		std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints <= 0)
	{
		std::cout
		<< "ClapTrap" << _name << " has no energy to repair" 
		<< std::endl;
		return;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout
	<< "ClapTrap " << _name << " repaired " << amount << " amount of health!"
	<< std::endl;
}

// Getter Functions
std::string&	ClapTrap::getName(void){return _name;}
int			ClapTrap::getHit(void) const {return _hitPoints;}
int			ClapTrap::getEnergy(void) const {return _energyPoints;}
int			ClapTrap::getAttack(void) const {return _attackPoints;}