/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:52:38 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:52:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){

}

HumanB::~HumanB(void){

}

void	HumanB::setWeapon(Weapon &weapon){

	this->_weapon = &weapon;

}

void	HumanB::attack(void){

	std::cout << this->_name << " attacks with their " << this->_weapon->getType();
	std::cout << std::endl;

}
