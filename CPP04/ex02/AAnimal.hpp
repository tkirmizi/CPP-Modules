/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:01:10 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 17:51:09 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <string>
#include <iostream>

class Animal{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		std::string getType() const;
		virtual void makeSound() const =0;
};

#endif