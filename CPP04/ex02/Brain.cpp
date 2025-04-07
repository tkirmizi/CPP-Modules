/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:37:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:45:36 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){std::cout << "Brain constructor called" << std::endl;}
Brain::Brain(const Brain &src){
	for (int i = 0 ; i < 100 ; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain& Brain::operator=(const Brain &src){
	if (this != &src){
		for (int i = 0 ; i < 100 ; i++)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}
Brain::~Brain(){std::cout << "Brain destructor called" << std::endl;}
