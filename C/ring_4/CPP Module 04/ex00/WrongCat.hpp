/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:24:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 18:24:55 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(WrongCat &src);
		~WrongCat(void);

		WrongCat & operator=(WrongCat const &rhs);

		std::string	getType(void) const;
		void	makeSound(void) const;

};


#endif