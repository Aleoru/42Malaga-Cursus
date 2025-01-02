/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:03:32 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){

	this->ClapTrap::_name = "DefaultDT_clap_name";
	this->_name = "DefaultDT";
	this->FragTrap::_hp = FragTrap::_hp;
	this->ScavTrap::_energy = ScavTrap::_energy;
	this->FragTrap::_dmg = FragTrap::_dmg;

	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	
}

DiamondTrap::DiamondTrap(std::string name){

	this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->FragTrap::_hp = FragTrap::_hp;
	this->ScavTrap::_energy = ScavTrap::_energy;
	this->FragTrap::_dmg = FragTrap::_dmg;

	std::cout << "DiamondTrap Parametized Constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src) {

	*this = src;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;

}

DiamondTrap::~DiamondTrap(){

	std::cout << "DiamondTrap Destructor called" << std::endl;

}

/* Overload assignation operator */

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs){

	if (this != &rhs){
		this->_name = rhs._name + "_clap_trap";
		this->FragTrap::_hp = rhs.FragTrap::_hp;
		this->ScavTrap::_energy = rhs.ScavTrap::_energy;
		this->FragTrap::_dmg = rhs.FragTrap::_dmg;
	}

	return *this;

}

/* Member Functions */

void	DiamondTrap::attack(const std::string &target){

	ScavTrap::attack(target);

}

void	DiamondTrap::whoAmI(void){

	std::cout << "Hi, my name is " << this->_name << ", a Diamond originated from ClapTrap ";
	std::cout << ClapTrap::_name << std::endl;

}