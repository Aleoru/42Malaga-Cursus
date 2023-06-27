/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:14:31 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 15:14:31 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){

	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain;

}

Dog::Dog(Dog &src): Animal(src) {

	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.type;

}

Dog::~Dog(void){

	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;

}

Dog	&Dog::operator=(Dog const &rhs){

	this->type = rhs.type;
	return *this;

}

void	Dog::makeSound(void) const{

	std::cout << "*Woof*" << std::endl;

}

std::string	Dog::getType(void) const{

	return this->type;

}