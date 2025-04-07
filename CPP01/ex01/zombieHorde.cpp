/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:13:35 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 17:23:39 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N ; i++)
		zombieHorde[i].setName(name);
	return zombieHorde;}