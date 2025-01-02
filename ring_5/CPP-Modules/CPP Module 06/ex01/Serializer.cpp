/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:47:09 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 20:26:56 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer &src){
	*this = src;
	std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer::~Serializer(void){
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &rhs){
	(void)rhs;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}