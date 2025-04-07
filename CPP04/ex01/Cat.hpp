/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:05:17 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:46:26 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		void makeSound() const override;
};

#endif