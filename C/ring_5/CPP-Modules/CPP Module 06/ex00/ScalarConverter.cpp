/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:08:11 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/13 20:14:42 by aoropeza         ###   ########.fr       */
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
	(void)rhs;
	return *this;	
}

static bool	isChar(std::string str) {
	return (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]));
}

bool	isInt(std::string str) {
	
	int	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < (int)str.length(); j++) {
		if (!std::isdigit(str[j]))
			return false;
	}
	return true;
}

bool	isFloat(std::string str) {

	if (str.find('.') == std::string::npos || str.find('.') == 0 || str.back() != 'f'
		|| str.find('.') == str.length() - 2)
		return false;
	
	int		i = 0;
	bool	p = false;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < (int)str.length() - 1; j++) {
		
		if(str[j] == '.' && !p)
			p = true;
		else if (!std::isdigit(str[j]) || (str[j] == '.' && p))
			return false;
	}
	return true;
	
}

bool	isDouble(std::string str) {

	if (str.find('.') == std::string::npos || str.find('.') == 0
		|| str.find('.') == str.length() - 1)
		return false;
	
	int		i = 0;
	bool	p = false;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < (int)str.length(); j++) {
		
		if(str[j] == '.' && !p)
			p = true;
		else if (!std::isdigit(str[j]) || (str[j] == '.' && p))
			return false;
	}
	return true;

}

bool	isLiteral(std::string str){
	if(!str.compare("nan") || !str.compare("nanf") || !str.compare("+inf")
		 || !str.compare("-inf") || !str.compare("+inff") || !str.compare("-inff"))
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string str){

	e_type	type;

	std::cout << "str: \"" << str << "\"" << std::endl;
	if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if(isFloat(str))
		type = FLOAT;
	else if(isDouble(str))
		type = DOUBLE;
	else if(isLiteral(str))
		type = LITERALS;
	else
		type = NONE;

	switch (type) {
		case CHAR:
			std::cout << "Soy Char-lie" << std::endl;
			break;
		case INT:
			std::cout << "Estoy Int-ero" << std::endl;
			break;
		case FLOAT:
			std::cout << "Estoy Float-ando" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Veo to' Double" << std::endl;
			break;
		case LITERALS:
			std::cout << "Literal-mente no se que poner" << std::endl;
			break;
		case NONE:
			std::cout << "Yo soy nada" << std::endl;
			break;
	}
}