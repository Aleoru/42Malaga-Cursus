/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:23 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 21:53:23 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria{

	public:
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		Cure &operator=(Cure const &rhs);
		
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);

};

#endif