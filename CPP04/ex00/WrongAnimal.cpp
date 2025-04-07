/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:09:39 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:16:07 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){std::cout << "WrongAnimal constructor called" << std::endl;};
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor called" << std::endl;};
WrongAnimal::WrongAnimal(const WrongAnimal &other){*this = other; std::cout << "WrongAnimal copy constructor called" << std::endl;};
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other)
		this->_type = other._type;
	return *this;}
void WrongAnimal::makeSound() const {std::cout << "WrongAnimal sound" << std::endl;};
