/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/11 19:27:11 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {

	Bureaucrat	Bureau("Eufrasio", 2);
	Intern someRandomIntern;
	AForm* rrf1;
	AForm* rrf2;
	
	rrf1 = someRandomIntern.makeForm("robotomy request", "Bender")
	try {
		rrf2 = someRandomIntern.makeForm("Shrubbery Creation", "Tree");
		if (B == nullptr)
			throw Intern::FormDoesNotExistException();
/* 		Bureau.signForm(B);
		Bureau.executeForm(B); */
	}
	catch (const Intern::FormDoesNotExistException e) {
		std::cerr << e.what() << std::endl;
	}
	delete B;
	return (0);

}