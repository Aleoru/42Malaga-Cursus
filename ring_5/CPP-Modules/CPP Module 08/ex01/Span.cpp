/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/03 19:19:05 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void){
	std::cout << "Span default constructor called" << std::endl;
}
Span::Span(unsigned int N) : _N(N) {
	_nums.resize(_N);
	//std::cout << "Span parametized constructor called" << std::endl;

}
Span::Span(Span &src){
	//std::cout << "Span copy constructor called" << std::endl;

}
Span::~Span(void){
	//std::cout << "Span destructor called" << std::endl;

}

void	Span::addNumber(int	num){

	_nums.push_back(num);
	std::cout << "size: " << _nums.size() << std::endl;

}