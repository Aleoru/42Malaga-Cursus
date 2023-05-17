/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:46:48 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:46:49 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str){

	this->_name.assign(str);

}

Zombie::~Zombie(void){

	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl; 

}

void	Zombie::announce(void){

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}
