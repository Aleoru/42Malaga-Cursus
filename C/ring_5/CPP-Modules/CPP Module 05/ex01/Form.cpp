/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:25:07 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:42:26 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("(default)"), _signGrade(1), _execGrade(1){
	_signed = false;
	//std::cout << "Bureaucraft Default constructor called" << std::endl;
}

Form::Form(std::string const name, int signGrade) : _name(name),
_signGrade(signGrade), _execGrade(0) {
	_signed = false;
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150)
		throw Form::GradeTooLowException();
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

Form::Form(std::string const name, int signGrade, int execGrade) : _name(name),
_signGrade(signGrade), _execGrade(execGrade) {
	_signed = false;
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _signed(src.getSigned()),
_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	//std::cout << "Bureaucraft Copy constructor called" << std::endl;
}

Form::~Form(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

void	Form::beSigned(const Bureaucrat& Bureau){
	if (Bureau.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::string	Form::getName(void) const {
	return this->_name;
}

int	Form::getSignGrade(void) const {
	return this->_signGrade;
}

int	Form::getExecGrade(void) const {
	return this->_execGrade;
}

bool	Form::getSigned(void) const {
	return this->_signed;
}

Form & Form::operator=(Form const & rhs) {

	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return *this;

}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << "Info:" << std::endl;
	o << "Form's name: " << rhs.getName() << std::endl;
	o << "Minimun Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "Minumun Grade to execute: " << rhs.getExecGrade();
	return o;
}