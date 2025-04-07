/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:07:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:16:23 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(){_type = "Dog"; std::cout << "Dog constructor called" << std::endl;};
Dog::~Dog(){std::cout << "Dog destructor called" << std::endl;};
Dog::Dog(const Dog &other){*this = other; std::cout << "Dog copy constructor called" << std::endl;};
Dog& Dog::operator=(const Dog &other){
	if (this != &other)
		this->_type = other._type;
		return *this;}
void Dog::makeSound() const {std::cout << "Woof Woof" << std::endl;};