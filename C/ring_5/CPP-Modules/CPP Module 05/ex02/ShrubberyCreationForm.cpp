/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:11:44 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/06 19:37:37 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("(default)"){
	//std::cout << "Bureaucraft Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
	//std::cout << "Bureaucraft Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target){
	//std::cout << "Bureaucraft Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

	if(!this->getSigned())
		throw AForm::IsNotSignedException();
	else if(executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

		std::ofstream	file(this->_target + "_shrubbery");

		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		
		file << "          &&& &&  & &&" << std::endl;
		file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		file << "     &&     \\|||" << std::endl;
		file << "             |||" << std::endl;
		file << "             |||" << std::endl;
		file << "             |||" << std::endl;
		file << "       , -=-~  .-^- _" << std::endl;
		file << "              `" << std::endl;

		file.close();
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