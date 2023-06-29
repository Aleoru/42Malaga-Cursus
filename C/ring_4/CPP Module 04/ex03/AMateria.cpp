/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:16:02 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 21:16:02 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type(""){

	std::cout << "* AMateria: materia is created with default constructor*" << std::endl;

}

AMateria::AMateria(std::string const &type)  : _type(type){

	std::cout << "AMateria " << this->_type << " created with parametized constructor" << std::endl;

}

AMateria::AMateria(AMateria const &src): _type(src._type) {

	std::cout << "AMateria " << this->_type << " created with copy constructor" << std::endl;

}

AMateria::~AMateria(void){

	std::cout << "AMateria " << this->_type << " destroyed" << std::endl;

}

std::string const & AMateria::getType() const{

	return this->_type;

}

AMateria* AMateria::clone() const{

	return (AMateria*)this;

}

void    AMateria::use(ICharacter& target){

	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;

}
