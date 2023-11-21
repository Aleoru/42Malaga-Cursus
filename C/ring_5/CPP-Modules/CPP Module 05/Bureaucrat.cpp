/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:34 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:09 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("(default)"), _grade(1) {

	std::cout << "Bureaucraft Default constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {

	std::cout << "Bureaucrat Parameterized constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;

}

Bureaucrat::~Bureaucrat(void) {

	std::cout << "Bureaucrat Destructor called" << std::endl;

}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::incGrade(void) {
	
	try
	{
		if (this->_grade - 1 < 1)
			throw "No se puede incrementar";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	this->_grade -= 1;
	
}

void	Bureaucrat::decGrade(void) {
	
	try
	{
		if (this->_grade + 1 > 150)
			throw "No se puede incrementar";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	this->_grade += 1;
	
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_grade = rhs.getGrade();
	}

	return *this;

}