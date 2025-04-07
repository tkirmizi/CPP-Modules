/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:07:22 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 19:58:24 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int main() {
	// Basic test
	// const Animal* i = new Animal(); // Error: cannot instantiate abstract class
	std::cout << "\n ========= TEST 1 =========\n" << std::endl;
	std::cout << "=== Animal -> Dog -> Brain Constructor Test ===" << std::endl;
	const Animal* dog = new Dog();
	std::cout << "\n=== Animal -> Cat -> Brain Constructor Test ===" << std::endl;
	const Animal* cat = new Cat();
	std::cout << "\n === Dog- > Brain -> Animal -> Destructor Test ===" << std::endl;
	delete dog;
	std::cout << "\n === Cat -> Brain -> Animal -> Destructor Test ===" << std::endl;
	delete cat;

	std::cout << "\n ========= TEST 2 =========" << std::endl;
	Dog* originalDog = new Dog();
	std::cout << "\n=== Deep copy constructon test ===" << std::endl;
	Dog* copyDog = new Dog(*originalDog);
	std::cout << "\n=== Destructon test ===" << std::endl;
	delete originalDog;
	delete copyDog;

	Animal* animals[4];
	for (int i = 0; i < 2; i++)
	{
		std::cout << "\n === Dog constrcton test === " << std::endl;
		animals[i] = new Dog();
	}

	for (int i = 2; i < 4; i++)
	{
		std::cout << "\n === Cat constrcton test === " << std::endl;
		animals[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << "\n === Destructon Test === " << std::endl;
		delete animals[i];
	}


	return 0;
}
