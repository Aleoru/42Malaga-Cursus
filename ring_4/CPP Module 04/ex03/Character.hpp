/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:46:58 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 21:46:58 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);
		
		Character &operator=(Character const &rhs);

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter &target);

};

#endif