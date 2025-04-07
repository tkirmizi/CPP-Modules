/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:36:25 by taha              #+#    #+#             */
/*   Updated: 2025/02/06 11:24:19 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

enum Levels {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain(Levels level);
		void writeAbove(int i);
		typedef void (Harl::*f)(void); // no param no return 
		f functionPtr[4];
		Harl();
};

Levels getLevel(std::string levelStr);


#endif