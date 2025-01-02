/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:21:23 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 18:21:23 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){

	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";

}

WrongAnimal::WrongAnimal(WrongAnimal &src){

	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = src.type;

}

WrongAnimal::~WrongAnimal(void){

	std::cout << "WrongAnimal destructor called" << std::endl;

}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs){

	this->type = rhs.type;
	return *this;

}

void	WrongAnimal::makeSound(void) const {

	std::cout << "*WrongAnimal sound*" << std::endl;

}

std::string	WrongAnimal::getType(void) const {

	return this->type;

}