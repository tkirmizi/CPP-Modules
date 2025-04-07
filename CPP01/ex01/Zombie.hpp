/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:56 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 17:25:25 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string newName);
		~Zombie();
		std::string getName(void);
		void setName(std::string newName);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif