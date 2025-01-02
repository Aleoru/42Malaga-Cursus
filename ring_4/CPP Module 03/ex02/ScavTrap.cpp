/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:27:41 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/20 12:27:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {

	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 20;

	std::cout << "ScavTrap Default constructor called" << std::endl;

}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {

	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 20;

	std::cout << "ScavTrap Parametized constructor called" << std::endl;

}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {

	std::cout << "ScavTrap Copy constructor called" << std::endl;

}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap Destructor for " << this->_name << " called" << std::endl;

}

/* Overload assignation operator */

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {

	if (this != &rhs){
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_energy = rhs._energy;
		this->_dmg = rhs._dmg;
	}
	return *this;

}

/* Member Functions */

void	ScavTrap::attack(const std::string &target){

	if (this->_energy > 0){
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg;
		std::cout << " points of damage!" << std::endl;

		this->_energy -= 1;
	}

}

void	ScavTrap::guardGate(void) {

	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;

}
