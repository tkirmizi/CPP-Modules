/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:07:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 19:57:35 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(){_type = "Dog"; std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();};
Dog::~Dog(){std::cout << "Dog destructor called" << std::endl;
	delete brain;};

Dog::Dog(const Dog &other)
	:Animal(other)
	{brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other._type;  
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {std::cout << "Woof Woof" << std::endl;};