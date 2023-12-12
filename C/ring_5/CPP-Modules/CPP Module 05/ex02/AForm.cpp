/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:25:07 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:42:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("(default)"), _signGrade(1), _execGrade(1){
	_signed = false;
	//std::cout << "Bureaucraft Default constructor called" << std::endl;
}

/* AForm::AForm(std::string const name, int signGrade) : _name(name),
_signGrade(signGrade), _execGrade(0) {
	_signed = false;
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
} */

AForm::AForm(std::string const name, int signGrade, int execGrade) : _name(name),
_signGrade(signGrade), _execGrade(execGrade) {
	_signed = false;
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src.getName()), _signed(src.getSigned()),
_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	//std::cout << "Bureaucraft Copy constructor called" << std::endl;
}

AForm::~AForm(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

void	AForm::beSigned(const Bureaucrat& Bureau){
	if (Bureau.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::string	AForm::getName(void) const {
	return this->_name;
}

int	AForm::getSignGrade(void) const {
	return this->_signGrade;
}

int	AForm::getExecGrade(void) const {
	return this->_execGrade;
}

bool	AForm::getSigned(void) const {
	return this->_signed;
}

AForm & AForm::operator=(AForm const & rhs) {

	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return *this;

}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	o << "Info:" << std::endl;
	o << "Form's name: " << rhs.getName() << std::endl;
	o << "Minimun Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "Minumun Grade to execute: " << rhs.getExecGrade();
	return o;
}