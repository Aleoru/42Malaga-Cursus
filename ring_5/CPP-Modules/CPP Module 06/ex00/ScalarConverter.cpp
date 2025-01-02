/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:08:11 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/21 19:39:02 by aoropeza         ###   ########.fr       */
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
	return (str.length() == 1 && (str[0] >= 32 && str[0] <= 127) && std::isprint(str[0]));
}

bool	isInt(std::string str) {
	
	int	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < static_cast<int>(str.length()); j++) {
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

	if (str[0] == '+' || str[0] == '-')
		i++;

	bool	p = false;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < static_cast<int>(str.length()) - 1; j++) {
		
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

	if (str[0] == '+' || str[0] == '-')
		i++;

	bool	p = false;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (int j(i); j < static_cast<int>(str.length()); j++) {
		
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


void	printChar(const std::string str) {

	char	c = str[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

}

void	printInt(const std::string str){

	int	i = std::stoi(str);

	if (std::isprint(i))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else if (!std::isprint(i) && i >= 0 && i <= CHAR_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;	

}

void	printFloat(const std::string str){

	float	f = std::stof(str);

	if (f == static_cast<int>(f) && std::isprint(f))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if (!std::isprint(f) && f > 0 && f < CHAR_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (f == static_cast<int>(f))
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;	
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;

}

void	printDouble(const std::string str){

	double	d = std::stod(str);

	if (d == static_cast<int>(d) && std::isprint(d))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (!std::isprint(d) && d > 0 && d < CHAR_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d == static_cast<int>(d))
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;	
	else
		std::cout << "double: " << d << std::endl;	

}

void	printLiterals(const std::string str){

	std::cout << "char: Impossible\nint: Impossible" << std::endl;

	if(!str.compare("nan"))
		std::cout << "float: " << str + "f" <<"\ndouble: " << str << std::endl;
	else if (!str.compare("nanf"))
		std::cout << "float: " << str << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;
	else if(!str.compare("+inf") || !str.compare("-inf"))
		std::cout << "float: " << str + "f" <<"\ndouble: " << str << std::endl;
	else if(!str.compare("+inff") || !str.compare("-inff"))
		std::cout << "float: " << str << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;

}

bool	isImpossible(const std::string str, e_type type){

	int		i;
	float	f;
	double	d;

	try {

		if (type == INT)
			i = std::stoi(str);
		else if (type == FLOAT)
			f = std::stof(str);
		else if (type == DOUBLE)
			d = std::stod(str);
		return false;

	} catch(std::exception & e) {
		return true;
	}

}

e_type	setType(const std::string str) {

	if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if(isFloat(str))
		return FLOAT;
	else if(isDouble(str))
		return DOUBLE;
	else if(isLiteral(str))
		return LITERALS;
	else
		return NONE;

}

void	ScalarConverter::convert(const std::string str){

	e_type	type = setType(str);

	if (isImpossible(str, type)){
		std::cout << "Imposible " << type << std::endl;
		return;
	}

	switch (type) {
		case CHAR:
			//std::cout << "Soy Char-lie" << std::endl;
			printChar(str);
			break;
		case INT:
			//std::cout << "Estoy Int-ero" << std::endl;
			//2147483647 || -2147483648
			printInt(str);
			break;
		case FLOAT:
			//std::cout << "Estoy Float-ando" << std::endl;
			printFloat(str);
			break;
		case DOUBLE:
			///std::cout << "Veo to' Double" << std::endl;
			printDouble(str);
			break;
		case LITERALS:
			//std::cout << "Literal-mente no se que poner" << std::endl;
			printLiterals(str);
			break;
		case NONE:
			throw ScalarConverter::ScalarConverterException();
	}
}