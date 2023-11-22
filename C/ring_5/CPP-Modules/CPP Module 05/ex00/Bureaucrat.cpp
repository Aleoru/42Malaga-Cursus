/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:34 by aoropeza          #+#    #+#             */
/*   Updated: 2023/11/22 18:40:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("(default)"), _grade(1) {

	//std::cout << "Bureaucraft Default constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	//std::cout << "Bureaucrat Parameterized constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src.getName()), _grade(src.getGrade())
{
	//std::cout << "Bureaucrat Copy constructor called" << std::endl;

}

Bureaucrat::~Bureaucrat(void) {

	//std::cout << "Bureaucrat Destructor called" << std::endl;

}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::incGrade(void) {

	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
	
}

void	Bureaucrat::decGrade(void) {

	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
	
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {

	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;

}