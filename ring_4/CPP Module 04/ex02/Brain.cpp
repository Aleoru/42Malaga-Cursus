/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:25:17 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 19:25:17 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_idea[i] = "Big brain idea";

}

Brain::Brain(const Brain &src) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;

}

Brain::~Brain(void){

	std::cout << "Brain destructor called" << std::endl;

}

Brain &Brain::operator=(Brain const &rhs){

	if(this != &rhs) {

		for (int i = 0; i < 100; i++){
			this->_idea[i] = rhs._idea[i];
		}

	}
	return *this;

}