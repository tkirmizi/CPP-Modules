/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:05:35 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 19:56:51 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(){_type = "Cat"; std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();};

Cat::~Cat(){std::cout << "Cat destructor called" << std::endl;
	delete brain;};
	
Cat::Cat(const Cat &other) : Animal(other) {
		std::cout << "Cat copy constructor called" << std::endl;
		brain = new Brain(*other.brain);}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;  
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {std::cout << "Meow Meow" << std::endl;};
