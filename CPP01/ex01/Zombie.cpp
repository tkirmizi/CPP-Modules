/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:12:26 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 17:23:09 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::Zombie(std::string newName): name(newName) {}
std::string Zombie::getName(void){return name;}
void Zombie::setName(std::string newName){name = newName;};
void Zombie::announce(void){ std::cout
	<< name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;}
Zombie::~Zombie(){}
