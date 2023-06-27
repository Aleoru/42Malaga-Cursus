/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:23:43 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 14:23:43 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	protected:
		std::string	type;
	
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal(void);

		Animal & operator=(Animal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

};

#endif