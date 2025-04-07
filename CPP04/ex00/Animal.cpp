/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:01:31 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:17:01 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("default"){std::cout << "Animal constructor called" << std::endl;};

Animal::Animal(std::string type):_type(type){std::cout << "Animal constructor called" << std::endl;};

Animal::~Animal(){std::cout << "Animal destructor called" << std::endl;};

Animal::Animal(const Animal &other){*this = other; std::cout << "Animal copy constructor called" << std::endl;};

Animal& Animal::operator=(const Animal &other){
	if (this != &other)
		this->_type = other._type;
	return *this;}

std::string Animal::getType() const{return _type;};

void Animal::makeSound() const {std::cout << "Animal sound" << std::endl;};
