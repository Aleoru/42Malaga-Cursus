/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:32:36 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 14:32:36 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(Dog &src);
		~Dog(void);

		Dog	&operator=(Dog const &rhs);

		std::string	getType(void) const;
		void		makeSound(void) const;

};

#endif