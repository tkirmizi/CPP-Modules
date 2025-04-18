/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:21 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 11:55:41 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(): _nbr(0){std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int n): _nbr(n << _frbits)
{std::cout << "Int constructor called" << std::endl;}

Fixed::Fixed (const float n): _nbr(std::roundf (n * (1 << _frbits)))
{std::cout << "Float constructor called" << std::endl;}

// Copy constructor
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl; 
	*this = other;
}

// Copy assgn operator
Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this != &other)
		this->_nbr = other._nbr;
	return *this;
}

// Destructor
Fixed::~Fixed()
{std::cout << "Destructor called" << std::endl;}

// Member functions
int Fixed::getRawbits(void) const{
	std::cout << "getRawbits member function called" << std::endl;
	return _nbr;
}

void Fixed::setRawbits(int const raw){
	_nbr = raw;
}

int Fixed::toInt( void ) const {
	return _nbr >> _frbits;
}

float Fixed::toFloat( void ) const {
	return (float)_nbr / 256;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj)
{
	os << fixedObj.toFloat();
	return os;
}

