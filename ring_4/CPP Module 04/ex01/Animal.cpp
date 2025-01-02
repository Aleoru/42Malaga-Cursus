/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:14:28 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 15:14:28 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){

	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";

}

Animal::Animal(std::string type){

	std::cout << "Animal parametized constructor called" << std::endl;
	this->type = type;

}

Animal::Animal(const Animal &src){

	std::cout << "Animal copy constructor called" << std::endl;
	this->type = src.type;

}

Animal::~Animal(void){

	std::cout << "Animal destructor called" << std::endl;

}

Animal	&Animal::operator=(Animal const &rhs){

	this->type = rhs.type;
	return *this;

}

void	Animal::makeSound(void) const {

	std::cout << "*Animal sound*" << std::endl;

}

std::string	Animal::getType(void) const {

	return this->type;

}