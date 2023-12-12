/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:08:11 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 18:32:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "Scalar Converter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << "Scalar Converter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "Scalar Converter destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & rhs) {
	return *this;	
}


void	ScalarConverter::convert(const std::string str){

	

}