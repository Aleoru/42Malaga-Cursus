/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:58:18 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 14:58:18 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {

	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(Cat &src);
		~Cat(void);

		Cat & operator=(Cat const &rhs);

		std::string	getType(void) const;
		void		makeSound(void) const;

};


#endif