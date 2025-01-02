/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:23:43 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 14:23:43 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal {

	protected:
		std::string	type;
	
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal(void) = 0;

		AAnimal & operator=(AAnimal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

};

#endif