/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:05:35 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 16:31:58 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(){_type = "Cat"; std::cout << "Cat constructor called" << std::endl;};
Cat::~Cat(){std::cout << "Cat destructor called" << std::endl;};
Cat::Cat(const Cat &other){*this = other; std::cout << "Cat copy constructor called" << std::endl;};
Cat& Cat::operator=(const Cat &other){
	if (this != &other)
		this->_type = other._type;
	return *this;
}
void Cat::makeSound() const {std::cout << "Meow Meow" << std::endl;};
