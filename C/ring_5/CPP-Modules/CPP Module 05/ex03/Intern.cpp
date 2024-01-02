/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:02:38 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 19:59:48 by aoropeza         ###   ########.fr       */
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
	//std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(const Intern &rhs){
	//std::cout << "Intern assignation overload called" << std::endl;
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	i = 0;

	while (i < 3 && forms[i].compare(name))
		i++;
	
	switch (i) {
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			return (nullptr);
	}

}