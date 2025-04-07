/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:07:52 by taha              #+#    #+#             */
/*   Updated: 2025/02/18 19:54:06 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"

int main(){
	std::vector<int> intVec {1,5,9,7};
	std::list<int> intList {0,2,4,6,8};
	try
		{auto it = easyfind(intVec, 5);std::cout << "found: "<< *it << std::endl;}
	catch(const std::exception &e)
		{std::cout << e.what() << std::endl;}

	try
		{auto it = easyfind(intVec, 0);std::cout << *it << std::endl;}
	catch(const std::exception &e)
		{std::cout << e.what() << std::endl;}

	try
		{auto it = easyfind(intList, 2); std::cout << "found: "<< *it << std::endl;}
	catch(const std::exception& e)
		{std::cout << e.what() << std::endl;}

	try
		{auto it = easyfind(intList, 5); std::cout << "found: "<< *it << std::endl;}
	catch(const std::exception& e)
		{std::cout << e.what() << std::endl;}
}