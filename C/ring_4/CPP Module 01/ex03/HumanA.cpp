/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:52:04 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:52:05 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){

}

HumanA::~HumanA(void){

}

void	HumanA::setWeapon(Weapon weapon){

	this->_weapon = weapon;

}

void	HumanA::attack(void){

	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
	std::cout << std::endl;

}
