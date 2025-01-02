/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:14:28 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 15:14:28 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void){

	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";

}

AAnimal::AAnimal(std::string type){

	std::cout << "AAnimal parametized constructor called" << std::endl;
	this->type = type;

}

AAnimal::AAnimal(const AAnimal &src){

	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = src.type;

}

AAnimal::~AAnimal(void){

	std::cout << "AAnimal destructor called" << std::endl;

}

AAnimal	&AAnimal::operator=(AAnimal const &rhs){

	this->type = rhs.type;
	return *this;

}

void	AAnimal::makeSound(void) const {

	std::cout << "*Animal sound*" << std::endl;

}

std::string	AAnimal::getType(void) const {

	return this->type;

}