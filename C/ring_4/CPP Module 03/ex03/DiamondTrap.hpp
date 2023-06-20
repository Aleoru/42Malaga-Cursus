/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:03:34 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:34 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap {

	private:
		std::string	_name;

	public:

		DiamondTrap(void);
		DiamondTrap(std::string	name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &rhs);

		void	attack(const std::string &target);
		void	whoAmI(void);

};


#endif