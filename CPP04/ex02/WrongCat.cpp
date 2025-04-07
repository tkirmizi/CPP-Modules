/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:11:18 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:15:43 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){std::cout << "WrongCat constructor called" << std::endl;};
WrongCat::~WrongCat(){std::cout << "WrongCat destructor called" << std::endl;};
WrongCat::WrongCat(const WrongCat &other){*this = other; std::cout << "WrongCat copy constructor called" << std::endl;};
WrongCat& WrongCat::operator=(const WrongCat &other){
	if (this != &other)
		this->_type = other._type;
	return *this;};
void WrongCat::makeSound() const {std::cout << "WrongCat sound" << std::endl;};