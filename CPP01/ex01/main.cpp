/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:51:01 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 17:12:24 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(3, "Taha");
	for (int i = 0; i < 3; i++)
		zombies[i].announce();
	delete [] zombies;
}