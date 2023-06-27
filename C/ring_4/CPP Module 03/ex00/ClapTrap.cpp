/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:13:31 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/17 16:13:31 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hp(10), _energy(10), _dmg(0) {

	std::cout << "Claptrap Default constructor called" << std::endl;

}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _dmg(0) {

	std::cout << "Claptrap Parametized constructor called" << std::endl;

}

ClapTrap::ClapTrap(ClapTrap const &src){

	std::cout << "Claptrap Copy constructor called" << std::endl;
	*this = src;

}

ClapTrap::~ClapTrap(void){

	std::cout << "Claptrap Destructor called" << std::endl;

}

/* Overload assignation operator */

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {

	if (this != &rhs){
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_energy = rhs._energy;
		this->_dmg = rhs._dmg;
	}
	return *this;

}

/* Member Functions */

void	ClapTrap::attack(const std::string &target){

	if (this->_energy > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg;
		std::cout << " points of damage!" << std::endl;

		this->_energy -= 1;
	}

}

void	ClapTrap::takeDamage(unsigned int amount){

	if (this->_hp > 0){
		std::cout << "ClapTrap " << this->_name << " gets hit and has ";
		
		this->_hp -= amount;

		if (this->_hp > 0)
			std::cout << this->_hp << " health points left." << std::endl;
		else
			std::cout << "0 health points left." << std::endl;
	}

}

void	ClapTrap::beRepaired(unsigned int amount){

	if (this->_energy > 0){
		std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " health points.";

		this->_hp += amount;
		this->_energy -= 1;

		std::cout << " Now it has " << this->_hp << " health points left." << std::endl;
	}

}

/* void ClapTrap::info(void)
{
    std::cout << "-------------INFO-----------------" << std::endl;
    std::cout << "Name:          " << this->_name << std::endl;
    std::cout << "Attack points: " << this->_dmg << std::endl;
    std::cout << "Hit points:    " << this->_hp << std::endl;
    std::cout << "Energy points: " << this->_energy << std::endl;
    std::cout << "----------------------------------" << std::endl;

} */
