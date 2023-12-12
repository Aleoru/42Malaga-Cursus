/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:02:38 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:56 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	//std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
	//std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(const Intern &rhs){
	//std::cout << "Intern assignation overload called" << std::endl;
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	
	if (!name.compare("presidential pardon")){
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (!name.compare("robotomy request")){
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (!name.compare("shrubbery creation")){
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else
		return (nullptr);

}