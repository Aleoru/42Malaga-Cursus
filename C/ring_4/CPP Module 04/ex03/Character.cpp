/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:56:28 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 22:56:28 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name): _name(name){

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "Character " << this->_name << " created" << std::endl;

}

Character::Character(Character const & src) : _name(src._name){
	
	*this = src;
	std::cout << "Character " << this->_name << " created" << std::endl;

}

Character::~Character(){

	std::cout << "Character " << this->_name << " destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];

}

Character& Character::operator=(Character const & rhs){

	if (this != &rhs)	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return *this;

}

void    Character::equip(AMateria* m) {

	for (int i = 0; i < 4; i++)
    if (this->_inventory[i] == NULL){
		this->_inventory[i] = m;
		std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
		return;
	}
	std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;

}

void    Character::unequip(int index) {

	if (this->_inventory[index]){
		delete this->_inventory[index];
		this->_inventory[index] = NULL;
		std::cout << "Character " << this->_name << " unequipped" << std::endl;
	}
	else
		std::cout << "Character " << this->_name << " can't unequip" << std::endl;

}

void    Character::use(int index, ICharacter& target) {

	if (this->_inventory[index]){
		this->_inventory[index]->use(target);
		std::cout << "Character " << this->_name << " uses " << this->_inventory[index]->getType() << std::endl;
	}
	else
		std::cout << "Character " << this->_name << " can't use" << std::endl;

}

std::string const& Character::getName() const {

	return this->_name;

}