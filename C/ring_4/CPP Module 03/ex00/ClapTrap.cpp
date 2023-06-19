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

ClapTrap::ClapTrap(void) : _name("null"), _hp(10), _energy(10), _dmg(0) {

	std::cout << "Default constructor called" << std::endl;

}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _dmg(0) {

	std::cout << "Parametized constructor called" << std::endl;

}

ClapTrap::ClapTrap(ClapTrap const &src){

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

}

ClapTrap::~ClapTrap(void){

	std::cout << "Destructor called" << std::endl;

}

/* Overload assignation operator */

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {

	if (this != &rhs){
		this->_name = rhs.getName();
		this->_hp = rhs.getHitPoints();
		this->_energy = rhs.getEnergyPoints();
		this->_dmg = rhs.getAttackDamage();
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

/* Getters */

std::string	ClapTrap::getName(void) const{
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const{
	return this->_hp;
}

unsigned int ClapTrap::getEnergyPoints(void) const{
	return this->_energy;
}

unsigned int ClapTrap::getAttackDamage(void) const{
	return this->_dmg;
}

