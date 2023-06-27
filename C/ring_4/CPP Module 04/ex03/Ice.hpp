/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:58:15 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 21:58:15 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria{

	public:
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);

		Ice & operator=(Ice const &rhs);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif