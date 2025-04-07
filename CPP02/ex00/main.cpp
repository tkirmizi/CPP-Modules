/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:56:52 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/07 10:15:36 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
orthodox canonical class
1. default const
2. copy cost
3. copy assing opr
4. dest
*/
// 128	64	32	16	8	4	2	1


#include "Fixed.hpp"

int main(){
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawbits() << std::endl;
	std::cout << b.getRawbits() << std::endl;
	std::cout << c.getRawbits() << std::endl;
}
