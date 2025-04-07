/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:35:14 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 16:39:07 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// int main() {
// 	int arr[] = {1, 2, 3, 4, 10, 12};
// 	std::cout << "Original int array: ";
// 	iter(arr, 6, print);
// 	std::cout << "\n";

// 	std::cout << "After doubling: ";
// 	iter(arr, 6, doubleVal);
// 	iter(arr, 6, print);
// 	std::cout << "\n";

// 	std::string sarr[] = {"bob", "jeniffer"};
// 	std::cout << "String array: ";
// 	iter(sarr, 2, print);
// 	std::cout << "\n";

// 	float farr[] = {1.1f, 2.2f, 3.3f};
// 	std::cout << "Float array: ";
// 	iter(farr, 3, print);
// 	std::cout << "\n";
// 	std::cout << "After doubling: ";
// 	iter(farr, 3, doubleVal);
// 	iter(farr, 3, print);
// 	std::cout << "\n";

// 	const int carr[] = {1, 2, 3};
// 	std::cout << "Const array: ";
// 	iter(carr, 3, print);
// 	std::cout << "\n";

// 	return 0;
// }

class Awesome {
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main(){
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}