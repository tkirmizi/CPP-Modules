/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:52:07 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:19:38 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "FragTrap constructor called" << std::endl;}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "FragTrap constructor called" << std::endl;}

FragTrap::FragTrap(const FragTrap &other)
:ClapTrap(other)
{std::cout << "FragTrap Copy Constructor called" << std::endl;}

FragTrap::~FragTrap(){std::cout << "FragTrap Destructor called" << std::endl;}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_attackPoints = other._attackPoints;
		this->_energyPoints = other._energyPoints;
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout
	<< "FragTrap " << _name << " requests a positive high five!"
	<< std::endl;
}