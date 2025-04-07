/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:53:18 by taha              #+#    #+#             */
/*   Updated: 2025/02/21 19:09:55 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <exception>
#include <algorithm>

class Nofind : public std::exception
{
	public:
		const char *what() const noexcept override;
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it =  std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	else
		throw Nofind();
	
}