/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:28:18 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 21:34:03 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void){
	std::string brain ("HI THIS IS BRAIN");
	std::string *strPtr = &brain;
	std::string &strRef = brain;

	std::cout
	<< &brain << std::endl
	<< strPtr << std::endl
	<< &strRef << std::endl << std::endl;

	std::cout
	<< brain << std::endl
	<< *strPtr << std::endl
	<< strRef << std::endl;
}