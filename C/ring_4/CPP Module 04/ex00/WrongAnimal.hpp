/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:21:26 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 18:21:26 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

	protected:
		std::string	type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &src);
		virtual ~WrongAnimal(void);

		WrongAnimal & operator=(WrongAnimal const &rhs);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;

};

#endif