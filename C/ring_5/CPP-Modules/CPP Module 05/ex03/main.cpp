/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:55 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/12 15:51:17 by aoropeza         ###   ########.fr       */
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
	
	rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
	try {
		//rrf2 = someRandomIntern.makeForm("shrubbery creation", "Tree");
		rrf2 = someRandomIntern.makeForm("fsasf creation", "Tree");
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