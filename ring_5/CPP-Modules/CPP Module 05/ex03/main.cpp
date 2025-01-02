/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/02 20:01:59 by aoropeza         ###   ########.fr       */
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
	
	try {
		rrf1 = someRandomIntern.makeForm("shrubbery creation", "Tree");
		if (rrf1 == nullptr)
			throw Intern::FormDoesNotExistException();
		Bureau.signForm(*rrf1);
		Bureau.executeForm(*rrf1);
		rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf2 == nullptr)
			throw Intern::FormDoesNotExistException();
		Bureau.signForm(*rrf2);
		Bureau.executeForm(*rrf2);
	}
	catch (const Intern::FormDoesNotExistException e) {
		std::cerr << e.what() << std::endl;
	}
	delete rrf1;
	delete rrf2;
	return (0);

}