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
	{std::cout << "ClapTrap Constructor called" << std::endl;};
	
// Constructor
ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0){std::cout << "ClapTrap Constructor called" << std::endl;};
ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack): _name(name), _hitPoints(hit), _energyPoints(energy), _attackPoints(attack){std::cout << "ClapTrap Constructor called" << std::endl;};

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackPoints(other._attackPoints)
	{std::cout << "ClapTrap Copy Constructor worked" <<  std::endl;}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackPoints = other._attackPoints;
	}
	std::cout << "ClapTrap Copy assignment operator called\n";
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(){std::cout << "ClapTrap Destructor called" << std::endl;}

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
	if (_energyPoints == 0)
	{
		std::cout
		<< "ClapTrap " << _name << "has no energy to attack"
		<< std::endl;
		return;
	}
	_hitPoints -= amount;
	std::cout
	<< "ClapTrap " << _name << " took damage, causing " << amount << " points of damage!" <<
	std::endl;
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout
		<< "ClapTrap" << _name << " died or has no energy" <<
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
std::string	ClapTrap::getName(void) const{return _name;}
int			ClapTrap::getHit(void) const{return _hitPoints;}
int			ClapTrap::getEnergy(void) const{return _energyPoints;}
int			ClapTrap::getAttack(void) const{return _attackPoints;}

// // Setter Functions
// void		ClapTrap::setName(std::string name){_name = name;}
// void		ClapTrap::setHit(int hit){_hitPoints = hit;}
// void		ClapTrap::setEnergy(int energy){_energyPoints = energy;}
// void		ClapTrap::setAttack(int attack){_attackPoints = attack;}
