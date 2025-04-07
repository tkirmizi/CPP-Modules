/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:37:54 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 16:45:08 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();
};

#endif