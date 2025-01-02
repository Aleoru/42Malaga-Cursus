/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:24:42 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/28 00:24:42 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
	// std::cout << "* Ice: materia is created *" << std::endl;
}

Ice::Ice(Ice const & src): AMateria("ice"){
	*this = src;
	// std::cout << "* Ice: materia is copied *" << std::endl;
}

Ice&	Ice::operator=(const Ice& rhs){
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

Ice::~Ice(){
	// std::cout << "* Ice: ice is destroyed *" << std::endl;
}

AMateria	*Ice::clone() const{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target ){
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}