/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:02:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:19:38 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// constructor
ScavTrap::ScavTrap()
	{std::cout << "ScavTrap Constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;}

// constructor
ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20)
	{std::cout << "ScavTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
	{std::cout << "ScavTrap Copy Constructor worked" <<  std::endl;}

//destructor
ScavTrap::~ScavTrap(){std::cout << "ScavTrap Destructor called" << std::endl;}

// copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_attackPoints = other._attackPoints;
		this->_energyPoints = other._energyPoints;
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;
}

// member functions
void ScavTrap::attack(const std::string& target){ //overloading
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has either energy or health"  << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout
	<< "ScavTrap " << _name << " attacks " << target
	<< ", causing " << _attackPoints << " points of damage!" <<
	std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}