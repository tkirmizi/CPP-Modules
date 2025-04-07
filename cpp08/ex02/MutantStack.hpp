/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:58:35 by taha              #+#    #+#             */
/*   Updated: 2025/02/27 14:11:34 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <string>
#include <stack>
#include <list>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {}
	MutantStack& operator=(const MutantStack &src);
	~MutantStack();

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T, Container>::operator=(src);
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() { return this->c.begin(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() { return this->c.end(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const { return this->c.begin(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const { return this->c.end(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() { return this->c.rbegin(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() { return this->c.rend(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const { return this->c.rbegin(); }

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const { return this->c.rend(); }
