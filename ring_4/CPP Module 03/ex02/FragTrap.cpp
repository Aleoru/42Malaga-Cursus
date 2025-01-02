/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:57:35 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/20 16:57:35 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {

	this->_hp = 100;
	this->_energy = 100;
	this->_dmg = 30;
	
	std::cout << "FragTrap Default constructor called" << std::endl;

}

FragTrap::FragTrap(std::string name): ClapTrap(name) {

	this->_hp = 100;
	this->_energy = 100;
	this->_dmg = 30;

	std::cout << "FragTrap Parametized constructor called" << std::endl;

}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src) {

	std::cout << "FragTrap Copy constructor called" << std::endl;

}

FragTrap::~FragTrap(void) {

	std::cout << "FragTrap Destructor for " << this->_name << " Called" << std::endl;

}

/* Overload assignation operator */

FragTrap	&FragTrap::operator=(FragTrap const &rhs){

	if (this != &rhs){
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_energy = rhs._energy;
		this->_dmg = rhs._dmg;
	}
	return *this;

}

/* Member Functions */

void	FragTrap::highFiveGuys(void){

	std::cout << "FragTrap " << this->_name << ": Hey! High five guys!!" << std::endl;

}