/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:41:02 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 20:11:33 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 145, 137), _target("(default)"){
	//std::cout << "Bureaucraft Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 145, 137), _target(target){
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target){
	//std::cout << "Bureaucraft Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{

	if(!this->getSigned())
		throw AForm::IsNotSignedException();
	else if(executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox";
		
}

AForm & AForm::operator=(AForm const & rhs) {

	if (this != &rhs) {
		(void)rhs;
	}
	return *this;

}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	o << "Info:" << std::endl;
	o << "Form's name: " << rhs.getName() << std::endl;
	o << "Target: " << rhs.getName() << std::endl;
	o << "Minimun Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "Minumun Grade to execute: " << rhs.getExecGrade();
	return o;
}