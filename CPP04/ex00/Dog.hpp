/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:07:12 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 14:14:07 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		void makeSound() const override;
};

#endif