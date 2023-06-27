/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:14:34 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/25 15:14:34 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){

	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain;

}

Cat::Cat(Cat &src): AAnimal(src) {

	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.type;

}

Cat::~Cat(void){

	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;

}

Cat	&Cat::operator=(Cat const &rhs){

	this->type = rhs.type;
	return *this;

}

void	Cat::makeSound(void) const {

	std::cout << "*Meow*" << std::endl;

}

std::string	Cat::getType(void) const {

	return this->type;

}