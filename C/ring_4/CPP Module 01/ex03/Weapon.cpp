/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:53:08 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:53:10 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){

}

Weapon::~Weapon(void){

}

const std::string&	Weapon::getType(void){
	return (this->_type);
}

void	Weapon::setType(std::string type){

	this->_type = type;

}
