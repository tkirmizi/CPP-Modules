/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:59:45 by taha              #+#    #+#             */
/*   Updated: 2025/02/27 14:19:50 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
	std::cout << "\n====Test1 - Basic MutantStack Functionality ====\n";
	MutantStack<int> mstack;
	try {
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top element: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
	
		std::cout << "MutantStack elements: ";
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	catch(std::exception const &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====Test2 - Comparing with std::list ====\n";
	std::list<int> lst;
	try {
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "Back element: " << lst.back() << std::endl;
		lst.pop_back();
		std::cout << "Size after pop: " << lst.size() << std::endl;
	
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
	
		std::cout << "List elements: ";
		std::list<int>::iterator lst_it = lst.begin();
		std::list<int>::iterator lst_ite = lst.end();
		while (lst_it != lst_ite) {
			std::cout << *lst_it << " ";
			++lst_it;
		}
		std::cout << std::endl;
	}
	catch(std::exception const &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====Test3 - Reverse Iterators ====\n";
	MutantStack<int> reverseTest;
	try {
		for (int i = 1; i <= 10; i++)
			reverseTest.push(i);
	
		std::cout << "MutantStack in reverse order: ";
		MutantStack<int>::reverse_iterator rit = reverseTest.rbegin();
		MutantStack<int>::reverse_iterator rite = reverseTest.rend();
		while (rit != rite) {
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}
	catch(std::exception const &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====Test4 - Using with different container ====\n";
	MutantStack<int, std::vector<int> > vectorStack;
	try {
		std::srand(std::time(0));
		for (int i = 0; i < 5; i++) {
			int num = std::rand() % 100;
			vectorStack.push(num);
			std::cout << "Pushed: " << num << std::endl;
		}
		std::cout << "VectorStack elements: ";
		MutantStack<int, std::vector<int> >::iterator vit = vectorStack.begin();
		MutantStack<int, std::vector<int> >::iterator vite = vectorStack.end();
		while (vit != vite) {
			std::cout << *vit << " ";
			++vit;
		}
		std::cout << std::endl;
	}
	catch(std::exception const &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	// std::stack<int> s(mstack);
// 	return 0;
// }

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }