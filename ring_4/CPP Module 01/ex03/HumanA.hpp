/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:52:23 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:52:24 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include <iostream>
#include "Weapon.hpp"

class HumanA{

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	setWeapon(Weapon weapon);
		void	attack(void);

	private:

		std::string	_name;
		Weapon		&_weapon;

};

#endif
