/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:24:53 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 18:24:53 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){

	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";

}

WrongCat::WrongCat(WrongCat &src): WrongAnimal(src) {

	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = src.type;

}

WrongCat::~WrongCat(void){

	std::cout << "WrongCat destructor called" << std::endl;

}

WrongCat	&WrongCat::operator=(WrongCat const &rhs){

	this->type = rhs.type;
	return *this;

}

void	WrongCat::makeSound(void) const {

	std::cout << "*Fake meow sound*" << std::endl;

}

std::string	WrongCat::getType(void) const{

	return this->type;

}